# PatternScanning
An Internal Pattern Scanner to find exact addresses.

Simple Pattern Scanner that takes 2 arguments. First is a pattern that we want to find and second is the Mask of this pattern.
Example : 
const BYTE pattern[] = { 0x80, 0x26, 0x66, 0x0E, 0xB0, 0x00 };
LPCSTR patternMask = "xxxxx?";
x - this is exact hex-value that we are looking for.
? - this is hex-value that changes every time we start our program.
The scanner scans the memory region from the start address to the end of the address of region.
