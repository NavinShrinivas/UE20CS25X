# Indexing methods 


Preindex : used to accessing values from an array 
preindex with writeback, autoindex : preindex with update to base address 
post indexing : direct write back to base address 

STR r1,[r0,#4] //preindex 
STR r1,[r0,4]! //preindex with writeback 
STR r2,[r0],#4 //postindex

1. Write a program in ARM ASM to find GCD off 2 number 
  - assume operands to be in CPU registers 
  - Assume opearnds to in memory location 
2. Write a program to in ARM ASM to find sum of N data items in the memory. Store result in memory
   locations. 
  - using preindex
  - using post indexing 
  - use auto indexing 
3. Write a program to find sum of N alternate [even or odd] data item in the memory. 
   Store result in memory locations.
  - using preindex
  - using post indexing 
  - use auto indexing 
4. Write a program to search an element from an array using : 
  - Linear search 
  - Binary search [use stack]\


1, 3ab
