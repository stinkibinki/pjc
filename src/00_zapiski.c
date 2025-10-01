#include <stdio.h>
#include <string.h>

int main() {
    printf("%d", strcmp("je", "je")); // if A > B -> false (-1)
}

// 01
// FORMATIRAN ZAPIS printf(format, parameters);
/* format: %[parameter][flags][width][.precision][length]
 *          width --> širina celotnega zapisa (including decimalke)
 *          precision --> št decimalnih mest
 * %d -> celo pedznačeno št (int), %u za unsigned int, %lld za long long int
 * %f -> realno št (float)
 * %c -> znak (char)
 * %s -> niz (char[])
 * %o -> število v osmiškem sistemu
 * %x, %X -> število v šestnajstiškem sistemu
 */
// ARGUMENTI PROGRAMA: main(int argc, char *args[]);
/* argc -> število argumentov
 * args[0] == ime programa, ostali so podani parametri
 * argumenti so vedno tipa string, atoi = string -> int
*/
// RANDOM
/* srand(seme); podamo seme s katerim zacnemo (seme= time(NULL)) #include <time.h>
 * rand(); generira random cifro
 * RAND_MAX je max podanega tipa (int, float)
 *     int interval = rand() / (int) RAND_MAX;
 *     return min + interval * (max-min);   max, min podana kor argumenta
 */

// 02
// BRANJE S TIPKOVNICE
/* getchar() -> brebere en znak 8dela šele po entru)
 * scanf(format, spremenljivka) -> prebere vrednost v spremenljivko
 * za %d moramo dati &spremelnjivka
 */

// 03
// PROGRAM V VEČ DATOTEKAH
/* funkcijo napišemo na začetek programa z main
 * spremenljivke zapišemo na začetek: extend int sprem;
 */
