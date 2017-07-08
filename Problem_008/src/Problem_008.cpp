#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

// NB NOT MY SOLUTION. Also, this solution doesn't give the right
// answer... hmm.... I'm done with this problem now :D

string num =    "73167176531330624919225119674426574742355349194934"\
                "96983520312774506326239578318016984801869478851843"\
                "85861560789112949495459501737958331952853208805511"\
                "12540698747158523863050715693290963295227443043557"\
                "66896648950445244523161731856403098711121722383113"\
                "62229893423380308135336276614282806444486645238749"\
                "30358907296290491560440772390713810515859307960866"\
                "70172427121883998797908792274921901699720888093776"\
                "65727333001053367881220235421809751254540594752243"\
                "52584907711670556013604839586446706324415722155397"\
                "53697817977846174064955149290862569321978468622482"\
                "83972241375657056057490261407972968652414535100474"\
                "82166370484403199890008895243450658541227588666881"\
                "16427171479924442928230863465674813919123162824586"\
                "17866458359124566529476545682848912883142607690042"\
                "24219022671055626321111109370544217506941658960408"\
                "07198403850962455444362981230987879927244284909188"\
                "84580156166097919133875499200524063689912560717606"\
                "05886116467109405077541002256983155200055935729725"\
                "71636269561882670428252483600823257530420752963450";

#define NUM_DIGITS 13

int main()
{
    long  maxprod=1;
    long  prod;
    int   maxcount=num.length()-NUM_DIGITS;

    // calculate initial product of first nth digits
    for (int i=0;i<NUM_DIGITS;i++)
        maxprod*=(num[i]-'0');

    prod=maxprod;

    // now at every iteration we divide the current product by the digit "exiting"
    // the calculation and multiply by the next one considered, in this way we can
    // avoid full calculations
    for (int i=1;i<maxcount;i++)
    {
        // we need to handle zeroes
        // skip to the next valid number, zero will make all products null
        if (num[i]=='0')
        {
            // skip consecutive zeros
            do
            {
                i++;
            }
            while ((num[i]=='0')&&(i<=maxcount));

            // no need for further calculations
            if (i>maxcount)
                break;

            // calculate product of next n digits
            prod=1;

            for (int j=i;j<i+NUM_DIGITS;j++)
                prod*=(num[j]-'0');
        }
        else
        {
            // divide by previous, multiply by next
            prod/=(num[i-1]-'0');
            prod*=(num[i+NUM_DIGITS-1]-'0');
        }

        // check for new max value
        if (prod>maxprod)
        {
            maxprod=prod;
            cout << maxprod << "\r\n";
        }
    }

    cout << maxprod << "\r\n";
    return 0;
}
