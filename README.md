# SHA256
Objective 

The team’s goal is to implement the cryptography hash algorithm, SHA-256, on an FPGA board using a C programming language. Since FPGA boards have the ability to implement reconfigurable hardware logic, they have an advantage over custom hardware when designing complex algorithms such as the SHA 256. We use the software program VITIS HLS to perform high-level synthesis to convert the C code into RTL (register transfer level) which can then be implemented on the FPGA board.  

The hash function should have the following properties, which would be checked either manually or through automated tests:

It is easy (but not necessarily quick) to compute the hash value for any given message. 

It is infeasible to generate a message that has a given hash. 

It is infeasible to modify a message without changing the hash. 

It is infeasible to find two different messages with the same hash. 

Explanation of the steps
Step1: this step converts the user input into its equivalent binary value. Next, these binary bits are appended in a manner where the total length of the message block is some multiple of 512. The last 64 bits, however, are used to indicate the length of the original message.

Step2: this step creates 8 hash values which are the first 32 bits of the fractional parts of the square roots of the first 8 primes: 2, 3, 5, 7, 11, 13, 17, 19
Step3: this step is similar to the above step, however, we create hash values with the first 32 bits of the fractional parts of the first 64 prime numbers (2 - 311) 

Step4: this step supplies 512 bits from the input bits to the next steps. This means that this step is repeated until all the input bits are used.

Step5: this steps consists of 3 substeps. A) Copying the the supplied bits into an new array where each entry is a 32 bit word. B) Adding 48 more words, which makes the array contains 64 words in total. C) Increase security by modifying the zero-ed indexes using a spciefic algorithm. 

Step6: this step initilizes variables from a to h and assigns them to the hash values created in step 2. Then it runs the comparison loop where variables are mutated.

Step 7: this step performs an OR operation between the values and their corresponding variables. The new values are then assigned to the the h values.

Step 8: this step the final hash digits is realized. The step concatnates the 8 hash values creating the SHA-256 hash. 


Conclusion 

Our aim is to conclude the project with an effective program that is maintainable, properly documented, and reusable. 

