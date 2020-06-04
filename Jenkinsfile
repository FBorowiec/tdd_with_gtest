pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                echo 'Building..'
		        sh 'bazel build //...'
                archiveArtifacts artifacts: 'bazel-*', fingerprint: true
            }
        }
    }
}
