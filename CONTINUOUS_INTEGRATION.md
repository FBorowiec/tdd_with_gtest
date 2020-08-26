# Continuous Integration

_"If debugging is the process of removing software bugs, then programming must be the process of putting them in."_ - **Edsger Dijkstra**

## **Motivation**

When embarking on a change, a developer takes a copy of the current code base on which to work. As other developers submit changed code to the source code repository, this copy gradually ceases to reflect the repository code. Not only can the existing code base change, but new code can be added as well as new libraries, and other resources that create dependencies, and potential conflicts.

The longer development continues on a branch without merging back to the mainline, the greater the risk of multiple integration conflicts and failures when the developer branch is eventually merged back. When developers submit code to the repository they must first update their code to reflect the changes in the repository since they took their copy. The more changes the repository contains, the more work developers must do before submitting their own changes.

Eventually, the repository may become so different from the developers' baselines that they enter what is sometimes referred to as "merge hell", or "integration hell", where the time it takes to integrate exceeds the time it took to make their original changes.

## **Workflows**

### **1. Run tests locally**

CI is intended to be used in combination with automated unit tests written through the practices of test-driven development. This is done by running and passing all unit tests in the developer's local environment before committing to the mainline. This helps avoid one developer's work-in-progress breaking another developer's copy. Where necessary, partially complete features can be disabled before committing, using feature toggles for instance.

### **2. Compile code in CI**

A build server compiles the code periodically or even after every commit and reports the results to the developers. The use of build servers had been introduced outside the XP (extreme programming) community and many organizations have adopted CI without adopting all of XP.

### **3. Run tests in CI**

In addition to automated unit tests, organizations using CI typically use a build server to implement continuous processes of applying quality control in general – small pieces of effort, applied frequently. In addition to running the unit and integration tests, such processes run additional static analyses, measure and profile performance, extract and format documentation from the source code and facilitate manual QA processes. On the popular Travis CI service for open-source, only 58.64% of CI jobs execute tests.[7]

This continuous application of quality control aims to improve the quality of software, and to reduce the time taken to deliver it, by replacing the traditional practice of applying quality control after completing all development. This is very similar to the original idea of integrating more frequently to make integration easier, only applied to QA processes.

### **4. Deploy an artifact from CI**

Now, CI is often intertwined with continuous delivery or continuous deployment in what is called CI/CD pipeline. CI makes sure the software checked in on the mainline is always in a state that can be deployed to users and CD makes the deployment process fully automated.

## **Best Practices**

* Maintain a code repository
* Automate the build
* Make the build self-testing
* Everyone commits to the baseline every day
* Every commit (to baseline) should be built
* Every bug-fix commit should come with a test case
* Keep the build fast
* Test in a clone of the production environment
* Make it easy to get the latest deliverables
* Everyone can see the results of the latest build
* Automate deployment

## **Jenkins**

Jenkins is a free and open source automation server. It helps automate the parts of software development related to building, testing, and deploying, facilitating continuous integration and continuous delivery. It is a server-based system that runs in _servlet_ containers such as Apache Tomcat.

### **Running Jenkins in a Docker container**

_You will need to have **Docker** installed on your computer._

Running a docker image containing Jenkins:

* `docker run -p 8080:8080 -p 50000:50000 -v /home/\${USER}/\${JENKINS_FOLDER}:/var/jenkins_home _DOCKER_WITH_JENKINS_`

E.g.:

* `docker run -p 8080:8080 -p 50000:50000 -v /home/\${USER}/jenkins_docker:/var/jenkins_home framaxwlad/jenkins_bazel`

Note: _Replace ${USER} with user's home directory._

Jenkins will then be exposed on the server you're running your Docker image or your `localhost` port `8080` if you run it locally:

* `firefox http://localhost:8080/`

### **Jenkinsfile**

Creating a Jenkinsfile, which is checked into source control, provides a number of immediate benefits:

* Code review/iteration on the Pipeline
* Audit trail for the Pipeline
* Single source of truth for the Pipeline, which can be viewed and edited by multiple members of the project.

Pipeline supports two syntaxes, Declarative and Scripted Pipeline. Both of which support building continuous delivery pipelines. Both may be used to define a Pipeline in either the web UI or with a Jenkinsfile, though it’s generally considered a best practice to create a Jenkinsfile and check the file into the source control repository.

#### **Creating a Jenkinsfile**

A Jenkinsfile is a text file that contains the definition of a Jenkins Pipeline and is checked into source control. Consider the following Pipeline which implements a basic three-stage continuous delivery pipeline.

Example of a Jenkinsfile running a bazel build of all targets:

```bash
pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        echo 'Building..'
        sh 'bazel build //...'
        sh 'bazel run //tdd_examples:tests'
        archiveArtifacts(artifacts: 'bazel-*', fingerprint: true)
      }
    }
  }
}
```

### **Running pipelines in Jenkins**

When your repository have a valid Jenkinsfile you can create a new pipeline. Choose the repo (ex. GitHub) where you store your code.
GitHub requires an access token.

To generate a new token go to:

1. > Your GitHub profile settings
2. > Developer settings
3. > Personal access tokens
4. > Generate new token:
   * Give full _repo_ access rights
   * Give full repository hoods _admin:public_key_ access rights
   * User details - _read:user_ and _user:email_
   * Generate Token

Paste the newly generated token into Jenkins and chose the repository you want to create a pipeline for.

If your Docker container runs on a server you might want to trigger the pipeline each time someone commits his modification. To do this you need to setup a webhook so the build gets automatically triggered.

1. Go to your repository settings
2. Webhooks > Add a webhook
3. Add the url of your server > [server](http://12.34.56.78:8080/github-webhook/)
4. Content type > application/json
5. Select just the _push_ event or any other event
6. Add webhook
