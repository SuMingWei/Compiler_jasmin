# Compiler Code Geneator(`jasmin`)

###### tags: `compiler` `lab3`

## Introduction
A ***µC*** compiler is expected to generate the ***Java assembly code*** (using Jasmin Instructions) with the input μC program. 

## Enviornment
* For Linux
    * Ubuntu 18.04 LTS
    * Install dependencies:
        ```bash=
        $ sudo apt install gcc flex bison python3 git
        ```
    * Java Virtual Machine (JVM)
        ```bash=
        $ sudo apt install default-jre
        ```
    * Java Assembler (Jasmin) is included in the file
## Java Assembly Code Generation
![](https://i.imgur.com/TowMfAB.png)


## Java Assembly Language 

* [Jasmin Instructions](https://en.wikipedia.org/wiki/Java_bytecode_instruction_listings)

## Setup Code
![](https://i.imgur.com/RCPXJeo.png)

## How to Debug
* Compile source code and feed the input to your program, then compare with the ground truth.
    ```bash=
    $ make clean && make
    $ ./myparser < input/in01_arithmetic.c  
    $ java -jar jasmin.jar hw3.j
    $ java Main
    ```
    ![](https://i.imgur.com/z5aOMaN.png)

## Judge
```bash=
python3 judge/judge.py
```
![](https://i.imgur.com/3xAmRTP.png)




    



