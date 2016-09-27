
NAME:  < David  >
 

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.

ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 7 >

How much memory will the map data structure require (order notation for memory use)?

The map data structures will require the number of unique kmers which is equal to the size of the map which is 
(the number of kmers divided by the number of different occurences).

Also another consideration is the size of the kmer, which is k, which would count toward the memory usage. 
The memory use of creating an index for a genome of length L is O(L - k).


What is the order notation for performance (running time) of each of
the commands?


set_random_kmer() function has an order notation of O(L*k)
checking() function has order notation of O(p*q)
get_line() and get_difference() functions have order notation of O(q)

The O notation of the genome filename is O(i)
The O notation for kmer k is O(L*k)
The O notation for query m query_string is O(q-k)
The O notation for quit is O(i)


The order notation of creating an index for a genome of length L is O(L * k)
The order notation of matching a query of length q in a genome of length L
with the key size of k and the key found at p different genome positions is 
O(log(size of map)*p*(q-k)).






