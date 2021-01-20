/* 
To keep things simple, when we use a divide-and-conquer algorithm to compute the matrix product C =  A * B, we assume that n is an exact power of 2 in each of the n 	x n matrices. We make this assumption because in each divide step, we will
divide n x n matrices into four n/2 * n/2 matrices, and by assuming that n is an exact power of 2, we are guaranteed that as long as n >= 2, the dimension n/2 is an
integer. 
*/

