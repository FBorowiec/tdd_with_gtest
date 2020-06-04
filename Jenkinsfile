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