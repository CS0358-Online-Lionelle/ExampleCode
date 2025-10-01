# Greedy Algorithms

Code for code alongs.

* startCode - Contains code for starting the code alongs
* solutionCode - provides solution files for each code along


## Generating Sample Data

You can generate sample data by running the `dag-generate.py` script in the samples directory. 

Examples:

```console
$ ./dag-generate.py > 10Random.txt
```
```console
$ ./dag-generate.py --vertices 100 > 100Random.txt
```

To generate the help message and see the options
```console
$ ./dag-generate.py -h
```

> [!NOTE]  
> Windows clients will need to include `python` in front of the script so `python dag-generate.py > 10Random.txt`.
> Mac or Linux you may need to add the +x permission, or use `python3` in front
> of the script.
>
> For mac and linux, including the `#!/usr/bin/env python3` at the top
> of the file tells the shell what program it needs to execute the script.
> That is why the script can be treated as an executable. Without that
> you would always need the program `python3` in front. 


Here is mermaid for the various sample graphs provided:

### Five Node Sample

```mermaid
flowchart TD
    0(("0"))
    1(("1"))
    2(("2"))
    3(("3"))
    4(("4"))
    
    0 -->|7| 1
    0 -->|9| 2
    0 -->|2| 3
    0 -->|5| 4
    1 -->|3| 2
    1 -->|2| 3
    1 -->|7| 4
    2 -->|5| 3
    2 -->|7| 4
    3 -->|5| 4
    
    classDef default fill:#f9f9f9,stroke:#333,stroke-width:2px;
```

### Five Node Sparse Sample

```mermaid
flowchart TD
    0(("0"))
    1(("1"))
    2(("2"))
    3(("3"))
    4(("4"))
    
    0 -->|1| 1
    0 -->|1| 2
    0 -->|10| 3
    1 -->|5| 3
    1 -->|8| 4
    3 -->|2| 4
    
    classDef default fill:#f9f9f9,stroke:#333,stroke-width:2px;
```


### 20 Vertices, 94 edges - Randomly Generated

```mermaid
flowchart TD
    %% Vertices
    0(("0"))
    1(("1"))
    2(("2"))
    3(("3"))
    4(("4"))
    5(("5"))
    6(("6"))
    7(("7"))
    8(("8"))
    9(("9"))
    10(("10"))
    11(("11"))
    12(("12"))
    13(("13"))
    14(("14"))
    15(("15"))
    16(("16"))
    17(("17"))
    18(("18"))
    19(("19"))
    
    %% Arrange vertices in a more structured way
    subgraph "Layer 1"
        0
    end
    
    subgraph "Layer 2"
        1
        3
        4
    end
    
    subgraph "Layer 3"
        2
        5
        6
        7
        8
    end
    
    subgraph "Layer 4"
        9
        10
        11
        12
        13
        14
        15
    end
    
    subgraph "Layer 5"
        16
        17
    end
    
    subgraph "Layer 6"
        18
        19
    end
    
    %% Edges from vertex 0
    0 --> 1
    0 --> 3
    0 --> 4
    0 --> 5
    0 --> 6
    0 --> 7
    0 --> 8
    0 --> 9
    0 --> 11
    0 --> 12
    0 --> 14
    
    %% Edges from vertex 1
    1 --> 2
    1 --> 5
    1 --> 6
    1 --> 7
    1 --> 11
    1 --> 15
    1 --> 18
    
    %% Edges from vertex 2
    2 --> 4
    2 --> 5
    2 --> 8
    2 --> 9
    2 --> 12
    2 --> 13
    2 --> 17
    
    %% Edges from vertex 3
    3 --> 5
    3 --> 6
    3 --> 10
    3 --> 12
    3 --> 13
    3 --> 14
    3 --> 17
    
    %% Edges from vertex 4
    4 --> 5
    4 --> 6
    4 --> 8
    4 --> 9
    4 --> 10
    4 --> 17
    
    %% Edges from vertex 5
    5 --> 7
    5 --> 9
    5 --> 10
    5 --> 11
    5 --> 12
    5 --> 15
    5 --> 18
    5 --> 19
    
    %% Edges from vertex 6
    6 --> 7
    6 --> 8
    6 --> 9
    6 --> 10
    6 --> 11
    6 --> 12
    6 --> 17
    
    %% Edges from vertex 7
    7 --> 9
    7 --> 15
    7 --> 16
    7 --> 17
    7 --> 18
    
    %% Edges from vertex 8
    8 --> 13
    8 --> 16
    8 --> 18
    8 --> 19
    
    %% Edges from vertex 9
    9 --> 10
    9 --> 14
    9 --> 16
    9 --> 17
    
    %% Edges from vertex 10
    10 --> 11
    10 --> 12
    10 --> 15
    10 --> 16
    10 --> 18
    10 --> 19
    
    %% Edges from vertex 11
    11 --> 14
    11 --> 17
    11 --> 18
    
    %% Edges from vertex 12
    12 --> 13
    12 --> 16
    12 --> 18
    12 --> 19
    
    %% Edges from vertex 13
    13 --> 14
    13 --> 16
    13 --> 17
    13 --> 19
    
    %% Edges from vertex 14
    14 --> 17
    14 --> 19
    
    %% Edges from vertex 15
    15 --> 16
    15 --> 17
    15 --> 18
    15 --> 19
    
    %% Edges from vertex 16
    16 --> 17
    16 --> 19
    
    %% Edges from vertex 17
    17 --> 18
    17 --> 19
    
    %% Node styling
    classDef default fill:#f9f9f9,stroke:#333,stroke-width:2px;
```

### Layered Sample
```mermaid
flowchart TD
    0(("0"))
    1(("1"))
    2(("2"))
    3(("3"))
    4(("4"))
    5(("5"))
    6(("6"))
    7(("7"))
    8(("8"))
    
    0 -->|3| 1
    0 -->|1| 2
    0 -->|2| 6
    1 -->|2| 3
    1 -->|9| 5
    2 -->|6| 4
    2 -->|5| 5
    3 -->|1| 8
    4 -->|8| 7
    5 -->|3| 8
    6 -->|8| 4
    7 -->|1| 8
    
    classDef default fill:#f9f9f9,stroke:#333,stroke-width:2px;
```