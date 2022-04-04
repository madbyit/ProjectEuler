/*
In the United Kingdom the currency is made up of pound (£) and pence (p). 
There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:
1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

using System;

namespace projecteuler
{
    class Solution
    {
        int NumberOfCombinations()
        {
            int target = 200;
            int[] coinSizes = { 1, 2, 5, 10, 20, 50, 100, 200 };
            int[] ways = new int[target+1];
            ways[0] = 1;
            int result = 0;
        
            for (int i = 0; i < coinSizes.Length; i++) 
            {
                for (int j = coinSizes[i]; j <= target; j++) 
                {
                    ways[j] += ways[j - coinSizes[i]];
                    result = ways[j];
                }
            }   

            return result;    
        }

        static void Main(string[] args)
        {
            Solution s = new Solution();
            Console.WriteLine(s.NumberOfCombinations());
        }
    }
}



//RESULT: 73682 is the correct answer