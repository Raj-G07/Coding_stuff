## Limitations of Rolling Hash 
-  Hash Collisions: Different strings may produce the same hash, leading to collisions. This 
requires a secondary check to ensure that the substrings actually match. 
-  Limited to Specific Hash Functions: Rolling hash works best with modular arithmetic-based 
hash functions and can be tricky with other types. 
-  Overflow Risks: Large hash values require careful handling with modular arithmetic to avoid 
overflow.