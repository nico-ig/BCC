# How to clone the repository
* To clone the entirely repository: `git clone --recurse-submodules https://github.com/nico-ig/BCC.git`
* To clone a specific submodule: `git submodule update --init <name_of_the_submodule>`
* If the repository has already been cloned: `git submodule update --init --recursive`

# How to add a new submodule
* If it is a github repository: `git submodule add ../<name_of_repository>.git`
* It it is in an external client: `git submodule add <url_to_repository>`

# Submodules in external clients
Submodules in external clients can be accesed in the browser by it's URL.

The submodules in external clients are:
* [raw-socket-c](https://gitlab.c3sl.ufpr.br/bfsc19/raw-socket-c).
