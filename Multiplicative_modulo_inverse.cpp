/*
(A.B) mod m = 1
then B is called the multiplicative modulo inverse of A modulo m

This B will exist if and only if A and m is co-prime, i.e gcd(A,m) = 1

This is an application of extended Euclid's algorithm

(A.B) mod m = 1 
then, (A.B - 1) mod m = 0
then, (A.B - 1) = m*q
then, A.B - m*q = 1
then, A.B + m.Q = 1
comparing with extended euclid's algo, A.x + B.y = 1.
we can easily find the sol. of Multiplicative Modulo inverse of A wrt m.
*/

