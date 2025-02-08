# cecho - Echo amélioré en C

## Disclaimer
This project is an experimentation and should not be used in production.

## Description
`cecho` ; echo function with color and style

## Compilation
```sh
gcc cecho.c -o cecho
```


## Exemple d'utilisation
```sh
./cecho --color=red --style=bold "I'm bold red"
./cecho --color=blue --style=underline "I'm underlined blue"
./cecho --color=cyan --style=inverse "I'm inverse cyan"
./cecho --color=yellow --style=italic "I'm italic yellow"
./cecho "Texte blanc par défaut"
```
