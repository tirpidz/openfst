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

REPOSITORY_DIRECTORY="${HOME}/src/openfst"

fetch_openfst() {
    VERSION_NUMBER=$1
    REVISION_NUMBER=$2

    echo "fetching openfst v${VERSION_NUMBER} r${REVISION_NUMBER}"

    cd ${REPOSITORY_DIRECTORY}
    rm -rf ${REPOSITORY_DIRECTORY}/OpenFst*
    wget "http://www.openfst.org/twiki/bin/viewfile/FST/FstDownload?filename=openfst-${VERSION_NUMBER}.tar.gz;rev=${REVISION_NUMBER}" -O OpenFst-v${VERSION_NUMBER}-r${REVISION_NUMBER}.tar.gz
    mkdir OpenFst
    tar -xf *gz -C OpenFst --strip-components 1
    git add .
    git commit -am "feat(OpenFst): ${VERSION_NUMBER} rev ${REVISION_NUMBER}"
    git tag -am v${VERSION_NUMBER}-r${REVISION_NUMBER} "openfst-v${VERSION_NUMBER}-r${REVISION_NUMBER}"
    git push --tags
    sleep 5
    echo "fetching done"
    echo "-------------"
}

fetch_openfst 1.0 1
fetch_openfst 1.1 1
fetch_openfst 1.1 2

fetch_openfst 1.2 1
fetch_openfst 1.2.1 1
fetch_openfst 1.2.2 1
fetch_openfst 1.2.3 1
fetch_openfst 1.2.4 1
fetch_openfst 1.2.5 1
fetch_openfst 1.2.6 1
fetch_openfst 1.2.7 1
fetch_openfst 1.2.7 2
fetch_openfst 1.2.8 1
fetch_openfst 1.2.8 2
fetch_openfst 1.2.9 1
fetch_openfst 1.2.10 1
fetch_openfst 1.2.11 1

fetch_openfst 1.3.1 1
fetch_openfst 1.3.2 1
fetch_openfst 1.3.2 2
fetch_openfst 1.3.2 3
fetch_openfst 1.3.2 4
fetch_openfst 1.3.3 1
fetch_openfst 1.3.3 2
fetch_openfst 1.3.4 1

fetch_openfst 1.4.0 1
fetch_openfst 1.4.1 1

fetch_openfst 1.5.0 1
fetch_openfst 1.5.0 2
fetch_openfst 1.5.0 3
fetch_openfst 1.5.1 1
fetch_openfst 1.5.1 2
fetch_openfst 1.5.1 3
fetch_openfst 1.5.1 4
fetch_openfst 1.5.1 5
fetch_openfst 1.5.1 6
fetch_openfst 1.5.1 7
fetch_openfst 1.5.1 8
fetch_openfst 1.5.2 1
fetch_openfst 1.5.3 1
fetch_openfst 1.5.3 2
fetch_openfst 1.5.3 3
fetch_openfst 1.5.4 1

fetch_openfst 1.6.0 1
fetch_openfst 1.6.0 2
fetch_openfst 1.6.1 1
fetch_openfst 1.6.2 1
fetch_openfst 1.6.3 1
fetch_openfst 1.6.4 1
fetch_openfst 1.6.5 1
fetch_openfst 1.6.6 1
fetch_openfst 1.6.7 1
fetch_openfst 1.6.8 1
fetch_openfst 1.6.9 1

fetch_openfst 1.7.0 1
fetch_openfst 1.7.1 1
fetch_openfst 1.7.2 1
fetch_openfst 1.7.3 1
fetch_openfst 1.7.4 1
fetch_openfst 1.7.5 1
fetch_openfst 1.7.6 1
fetch_openfst 1.7.7 1
fetch_openfst 1.7.8 1
fetch_openfst 1.7.9 1

fetch_openfst 1.8.0 1
fetch_openfst 1.8.1 1