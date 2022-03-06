# Session-06

## Student Excersise : 

- Sum of all digits in a 32 bit number
  - r0 : Stores the last number (lsd)
  - uint32(x / 10) = uint64(x * 0xcccccccd) >> 35
  - Ahhhh so the concept of magic number, lmao it works.
  - [!link to understand magic number](https://stackoverflow.com/questions/23065711/divide-by-10-in-assembly-not-giving-correct-result/23070559#23070559)
- Number of ocurrences of a given charecter in a string
