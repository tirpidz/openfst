set -euo pipefail
# http://redsymbol.net/articles/unofficial-bash-strict-mode/
# -e
# The set -e option instructs bash to immediately exit if any command [1] has a non-zero exit status. 
# -u
# Treat unset variables and parameters other than the special parameters "@" and "*" as an error
# when performing parameter expansion. If expansion is attempted on an unset variable or parameter,
# the shell prints an error message, and, if not interactive, exits with a non-zero status.
# set -o pipefail
# This setting prevents errors in a pipeline from being masked. If any command in a pipeline fails,
# that return code will be used as the return code of the whole pipeline.

REPOSITORY_DIRECTORY="~/src/openfst"

fetch_openfst() {
    VERSION_NUMBER=$1
    REVISION_NUMBER=$2

    cd ${REPOSITORY_DIRECTORY}
    wget "http://www.openfst.org/twiki/bin/viewfile/FST/FstDownload?filename=openfst-${VERSION_NUMBER}.tar.gz;rev=${REVISION_NUMBER}"
    rm -rf ${REPOSITORY_DIRECTORY}/OpenFst*
    mkdir OpenFst
    tar -xf *gz -C OpenFst --strip-components 1
    git add .
    git commit "feat(OpenFst): ${VERSION_NUMBER} rev ${REVISION_NUMBER}"
    git tag -am v${VERSION_NUMBER}-r${REVISION_NUMBER} "openfst-v${VERSION_NUMBER}-r${REVISION_NUMBER}"
    git push --tags
}

fetch_openfst 1.0 1
