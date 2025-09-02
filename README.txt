# These are my solutions to the exercises from the book "The C Programming Language" by Brian Kernighan and Dennis Ritchie

## Some notes on some solutions:

### Exercise 1-23 (remove-comments)
Includes support for removing both multi-line (C-style) comments and single-line comments.

The detection mechanism for muti-line comments is somewhat sophisticated. It does 3 notable detections:
1. Correctly ignores // and /* patterns that are inside of strings
2. Correctly prevents escape sequence \" characters from messing with the previous detection
3. Correctly prevents additional text on the same line as the closing */ pattern from being deleted. Granted, it doesn't do it in the cleanest way possible, which is a change that can be considered in the future

There are a few other logic-based detections that make the output more accurate, feel free to look at the code and see them inside the findMultiComments() and findSingleComments() functions.
