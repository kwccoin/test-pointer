# comment to author

## see https://github.com/kenbod/5828_F16_Code/issues/1

reading your source under

https://www.cs.colorado.edu/~kena/classes/5448/f12/presentation-materials/gatchell.pdf

I think the delete and the find logic has some issues.  If you delete the object, your find logic using assert is not ok.  Basically you rely upon

set - heap -> in set
MANY -> new and drop and hence not in set
0 -> delete

But the assert in find assume only in set or new or drop but not delete case.

Hence instead of

    assert(* element);  // problem with this statement as it could be 0 after delete!!!
    return * element == set - heap ? (void *) element : 0;

You should

    return * element == set - heap ? (void *) element : 0;

For your kind consideration.




