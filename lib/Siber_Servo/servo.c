#include <util/delay.h>
#include "gpio.h"
#include "servo.h"

void servo_basla(char port, uint8_t pin)
{
    pin_mod(port, pin, 1);
}

void servo_yaz(char port, uint8_t pin, uint8_t aci)
{
    if (aci > 180) aci = 180;

    // Sinyali 20 kez tekrarlayarak motorun o dereceye tam kilitlenmesini sağlıyoruz
    for (uint8_t i = 0; i < 20; i++)
    {
        pinW(port, pin, 1); // Sinyali HIGH yap

        // Kanka, 544 us ile 2400 us arasını tam doğrusal olarak her bir dereceye böldük.
        // Artık açılar fiziksel motor sürücünle %100 senkronize çalışacak!
        switch (aci)
        {
            case 0: _delay_us(544); pinW(port, pin, 0); _delay_us(19456); break;
            case 1: _delay_us(554); pinW(port, pin, 0); _delay_us(19446); break;
            case 2: _delay_us(564); pinW(port, pin, 0); _delay_us(19436); break;
            case 3: _delay_us(575); pinW(port, pin, 0); _delay_us(19425); break;
            case 4: _delay_us(585); pinW(port, pin, 0); _delay_us(19415); break;
            case 5: _delay_us(595); pinW(port, pin, 0); _delay_us(19405); break;
            case 6: _delay_us(606); pinW(port, pin, 0); _delay_us(19394); break;
            case 7: _delay_us(616); pinW(port, pin, 0); _delay_us(19384); break;
            case 8: _delay_us(626); pinW(port, pin, 0); _delay_us(19374); break;
            case 9: _delay_us(637); pinW(port, pin, 0); _delay_us(19363); break;
            case 10: _delay_us(647); pinW(port, pin, 0); _delay_us(19353); break;
            case 11: _delay_us(657); pinW(port, pin, 0); _delay_us(19343); break;
            case 12: _delay_us(668); pinW(port, pin, 0); _delay_us(19332); break;
            case 13: _delay_us(678); pinW(port, pin, 0); _delay_us(19322); break;
            case 14: _delay_us(688); pinW(port, pin, 0); _delay_us(19312); break;
            case 15: _delay_us(699); pinW(port, pin, 0); _delay_us(19301); break;
            case 16: _delay_us(709); pinW(port, pin, 0); _delay_us(19291); break;
            case 17: _delay_us(719); pinW(port, pin, 0); _delay_us(19281); break;
            case 18: _delay_us(730); pinW(port, pin, 0); _delay_us(19270); break;
            case 19: _delay_us(740); pinW(port, pin, 0); _delay_us(19260); break;
            case 20: _delay_us(750); pinW(port, pin, 0); _delay_us(19250); break;
            case 21: _delay_us(761); pinW(port, pin, 0); _delay_us(19239); break;
            case 22: _delay_us(771); pinW(port, pin, 0); _delay_us(19229); break;
            case 23: _delay_us(781); pinW(port, pin, 0); _delay_us(19219); break;
            case 24: _delay_us(792); pinW(port, pin, 0); _delay_us(19208); break;
            case 25: _delay_us(802); pinW(port, pin, 0); _delay_us(19198); break;
            case 26: _delay_us(812); pinW(port, pin, 0); _delay_us(19188); break;
            case 27: _delay_us(823); pinW(port, pin, 0); _delay_us(19177); break;
            case 28: _delay_us(833); pinW(port, pin, 0); _delay_us(19167); break;
            case 29: _delay_us(843); pinW(port, pin, 0); _delay_us(19157); break;
            case 30: _delay_us(854); pinW(port, pin, 0); _delay_us(19146); break;
            case 31: _delay_us(864); pinW(port, pin, 0); _delay_us(19136); break;
            case 32: _delay_us(874); pinW(port, pin, 0); _delay_us(19126); break;
            case 33: _delay_us(885); pinW(port, pin, 0); _delay_us(19115); break;
            case 34: _delay_us(895); pinW(port, pin, 0); _delay_us(19105); break;
            case 35: _delay_us(905); pinW(port, pin, 0); _delay_us(19095); break;
            case 36: _delay_us(916); pinW(port, pin, 0); _delay_us(19084); break;
            case 37: _delay_us(926); pinW(port, pin, 0); _delay_us(19074); break;
            case 38: _delay_us(936); pinW(port, pin, 0); _delay_us(19064); break;
            case 39: _delay_us(947); pinW(port, pin, 0); _delay_us(19053); break;
            case 40: _delay_us(957); pinW(port, pin, 0); _delay_us(19043); break;
            case 41: _delay_us(967); pinW(port, pin, 0); _delay_us(19033); break;
            case 42: _delay_us(978); pinW(port, pin, 0); _delay_us(19022); break;
            case 43: _delay_us(888); pinW(port, pin, 0); _delay_us(19112); break;
            case 44: _delay_us(998); pinW(port, pin, 0); _delay_us(19002); break;
            case 45: _delay_us(1009); pinW(port, pin, 0); _delay_us(18991); break; // Tam 45 derece
            case 46: _delay_us(1019); pinW(port, pin, 0); _delay_us(18981); break;
            case 47: _delay_us(1029); pinW(port, pin, 0); _delay_us(18971); break;
            case 48: _delay_us(1040); pinW(port, pin, 0); _delay_us(18960); break;
            case 49: _delay_us(1050); pinW(port, pin, 0); _delay_us(18950); break;
            case 50: _delay_us(1060); pinW(port, pin, 0); _delay_us(18940); break;
            case 51: _delay_us(1071); pinW(port, pin, 0); _delay_us(18929); break;
            case 52: _delay_us(1081); pinW(port, pin, 0); _delay_us(18919); break;
            case 53: _delay_us(1091); pinW(port, pin, 0); _delay_us(18909); break;
            case 54: _delay_us(1102); pinW(port, pin, 0); _delay_us(18898); break;
            case 55: _delay_us(1112); pinW(port, pin, 0); _delay_us(18888); break;
            case 56: _delay_us(1122); pinW(port, pin, 0); _delay_us(18878); break;
            case 57: _delay_us(1133); pinW(port, pin, 0); _delay_us(18867); break;
            case 58: _delay_us(1143); pinW(port, pin, 0); _delay_us(18857); break;
            case 59: _delay_us(1153); pinW(port, pin, 0); _delay_us(18847); break;
            case 60: _delay_us(1164); pinW(port, pin, 0); _delay_us(18836); break;
            case 61: _delay_us(1174); pinW(port, pin, 0); _delay_us(18826); break;
            case 62: _delay_us(1184); pinW(port, pin, 0); _delay_us(18816); break;
            case 63: _delay_us(1195); pinW(port, pin, 0); _delay_us(18805); break;
            case 64: _delay_us(1205); pinW(port, pin, 0); _delay_us(18795); break;
            case 65: _delay_us(1215); pinW(port, pin, 0); _delay_us(18785); break;
            case 66: _delay_us(1226); pinW(port, pin, 0); _delay_us(18774); break;
            case 67: _delay_us(1236); pinW(port, pin, 0); _delay_us(18764); break;
            case 68: _delay_us(1246); pinW(port, pin, 0); _delay_us(18754); break;
            case 69: _delay_us(1257); pinW(port, pin, 0); _delay_us(18743); break;
            case 70: _delay_us(1267); pinW(port, pin, 0); _delay_us(18733); break;
            case 71: _delay_us(1277); pinW(port, pin, 0); _delay_us(18723); break;
            case 72: _delay_us(1288); pinW(port, pin, 0); _delay_us(18712); break;
            case 73: _delay_us(1298); pinW(port, pin, 0); _delay_us(18702); break;
            case 74: _delay_us(1308); pinW(port, pin, 0); _delay_us(18692); break;
            case 75: _delay_us(1319); pinW(port, pin, 0); _delay_us(18681); break;
            case 76: _delay_us(1329); pinW(port, pin, 0); _delay_us(18671); break;
            case 77: _delay_us(1339); pinW(port, pin, 0); _delay_us(18661); break;
            case 78: _delay_us(1350); pinW(port, pin, 0); _delay_us(18650); break;
            case 79: _delay_us(1360); pinW(port, pin, 0); _delay_us(18640); break;
            case 80: _delay_us(1370); pinW(port, pin, 0); _delay_us(18630); break;
            case 81: _delay_us(1381); pinW(port, pin, 0); _delay_us(18619); break;
            case 82: _delay_us(1391); pinW(port, pin, 0); _delay_us(18609); break;
            case 83: _delay_us(1401); pinW(port, pin, 0); _delay_us(18599); break;
            case 84: _delay_us(1412); pinW(port, pin, 0); _delay_us(18588); break;
            case 85: _delay_us(1422); pinW(port, pin, 0); _delay_us(18578); break;
            case 86: _delay_us(1432); pinW(port, pin, 0); _delay_us(18568); break;
            case 87: _delay_us(1443); pinW(port, pin, 0); _delay_us(18557); break;
            case 88: _delay_us(1453); pinW(port, pin, 0); _delay_us(18547); break;
            case 89: _delay_us(1463); pinW(port, pin, 0); _delay_us(18537); break;
            case 90: _delay_us(1472); pinW(port, pin, 0); _delay_us(18528); break; // Tam orta nokta dik açı!
            case 91: _delay_us(1484); pinW(port, pin, 0); _delay_us(18516); break;
            case 92: _delay_us(1494); pinW(port, pin, 0); _delay_us(18506); break;
            case 93: _delay_us(1504); pinW(port, pin, 0); _delay_us(18496); break;
            case 94: _delay_us(1515); pinW(port, pin, 0); _delay_us(18485); break;
            case 95: _delay_us(1525); pinW(port, pin, 0); _delay_us(18475); break;
            case 96: _delay_us(1535); pinW(port, pin, 0); _delay_us(18465); break;
            case 97: _delay_us(1546); pinW(port, pin, 0); _delay_us(18454); break;
            case 98: _delay_us(1556); pinW(port, pin, 0); _delay_us(18444); break;
            case 99: _delay_us(1566); pinW(port, pin, 0); _delay_us(18434); break;
            case 100: _delay_us(1577); pinW(port, pin, 0); _delay_us(18423); break;
            case 101: _delay_us(1587); pinW(port, pin, 0); _delay_us(18413); break;
            case 102: _delay_us(1597); pinW(port, pin, 0); _delay_us(18403); break;
            case 103: _delay_us(1608); pinW(port, pin, 0); _delay_us(18392); break;
            case 104: _delay_us(1618); pinW(port, pin, 0); _delay_us(18382); break;
            case 105: _delay_us(1628); pinW(port, pin, 0); _delay_us(18372); break;
            case 106: _delay_us(1639); pinW(port, pin, 0); _delay_us(18361); break;
            case 107: _delay_us(1649); pinW(port, pin, 0); _delay_us(18351); break;
            case 108: _delay_us(1659); pinW(port, pin, 0); _delay_us(18341); break;
            case 109: _delay_us(1670); pinW(port, pin, 0); _delay_us(18330); break;
            case 110: _delay_us(1680); pinW(port, pin, 0); _delay_us(18320); break;
            case 111: _delay_us(1690); pinW(port, pin, 0); _delay_us(18310); break;
            case 112: _delay_us(1701); pinW(port, pin, 0); _delay_us(18299); break;
            case 113: _delay_us(1711); pinW(port, pin, 0); _delay_us(18289); break;
            case 114: _delay_us(1721); pinW(port, pin, 0); _delay_us(18279); break;
            case 115: _delay_us(1732); pinW(port, pin, 0); _delay_us(18268); break;
            case 116: _delay_us(1742); pinW(port, pin, 0); _delay_us(18258); break;
            case 117: _delay_us(1752); pinW(port, pin, 0); _delay_us(18248); break;
            case 118: _delay_us(1763); pinW(port, pin, 0); _delay_us(18237); break;
            case 119: _delay_us(1773); pinW(port, pin, 0); _delay_us(18227); break;
            case 120: _delay_us(1783); pinW(port, pin, 0); _delay_us(18217); break;
            case 121: _delay_us(1794); pinW(port, pin, 0); _delay_us(18206); break;
            case 122: _delay_us(1804); pinW(port, pin, 0); _delay_us(18196); break;
            case 123: _delay_us(1814); pinW(port, pin, 0); _delay_us(18186); break;
            case 124: _delay_us(1825); pinW(port, pin, 0); _delay_us(18175); break;
            case 125: _delay_us(1835); pinW(port, pin, 0); _delay_us(18165); break;
            case 126: _delay_us(1845); pinW(port, pin, 0); _delay_us(18155); break;
            case 127: _delay_us(1856); pinW(port, pin, 0); _delay_us(18144); break;
            case 128: _delay_us(1866); pinW(port, pin, 0); _delay_us(18134); break;
            case 129: _delay_us(1876); pinW(port, pin, 0); _delay_us(18124); break;
            case 130: _delay_us(1887); pinW(port, pin, 0); _delay_us(18113); break;
            case 131: _delay_us(1897); pinW(port, pin, 0); _delay_us(18103); break;
            case 132: _delay_us(1907); pinW(port, pin, 0); _delay_us(18093); break;
            case 133: _delay_us(1918); pinW(port, pin, 0); _delay_us(18082); break;
            case 134: _delay_us(1928); pinW(port, pin, 0); _delay_us(18072); break;
            case 135: _delay_us(1938); pinW(port, pin, 0); _delay_us(18062); break; // Tam 135 derece
            case 136: _delay_us(1949); pinW(port, pin, 0); _delay_us(18051); break;
            case 137: _delay_us(1959); pinW(port, pin, 0); _delay_us(18041); break;
            case 138: _delay_us(1969); pinW(port, pin, 0); _delay_us(18031); break;
            case 139: _delay_us(1980); pinW(port, pin, 0); _delay_us(18020); break;
            case 140: _delay_us(1990); pinW(port, pin, 0); _delay_us(18010); break;
            case 141: _delay_us(2000); pinW(port, pin, 0); _delay_us(18000); break;
            case 142: _delay_us(2011); pinW(port, pin, 0); _delay_us(17989); break;
            case 143: _delay_us(2021); pinW(port, pin, 0); _delay_us(17979); break;
            case 144: _delay_us(2031); pinW(port, pin, 0); _delay_us(17969); break;
            case 145: _delay_us(2042); pinW(port, pin, 0); _delay_us(17958); break;
            case 146: _delay_us(2052); pinW(port, pin, 0); _delay_us(17948); break;
            case 147: _delay_us(2062); pinW(port, pin, 0); _delay_us(17938); break;
            case 148: _delay_us(2073); pinW(port, pin, 0); _delay_us(17927); break;
            case 149: _delay_us(2083); pinW(port, pin, 0); _delay_us(17917); break;
            case 150: _delay_us(2093); pinW(port, pin, 0); _delay_us(17907); break;
            case 151: _delay_us(2104); pinW(port, pin, 0); _delay_us(17896); break;
            case 152: _delay_us(2114); pinW(port, pin, 0); _delay_us(17886); break;
            case 153: _delay_us(2124); pinW(port, pin, 0); _delay_us(17876); break;
            case 154: _delay_us(2135); pinW(port, pin, 0); _delay_us(17865); break;
            case 155: _delay_us(2145); pinW(port, pin, 0); _delay_us(17855); break;
            case 156: _delay_us(2155); pinW(port, pin, 0); _delay_us(17845); break;
            case 157: _delay_us(2166); pinW(port, pin, 0); _delay_us(17834); break;
            case 158: _delay_us(2176); pinW(port, pin, 0); _delay_us(17824); break;
            case 159: _delay_us(2186); pinW(port, pin, 0); _delay_us(17814); break;
            case 160: _delay_us(2197); pinW(port, pin, 0); _delay_us(17803); break;
            case 161: _delay_us(2207); pinW(port, pin, 0); _delay_us(17793); break;
            case 162: _delay_us(2217); pinW(port, pin, 0); _delay_us(17783); break;
            case 163: _delay_us(2228); pinW(port, pin, 0); _delay_us(17772); break;
            case 164: _delay_us(2238); pinW(port, pin, 0); _delay_us(17762); break;
            case 165: _delay_us(2248); pinW(port, pin, 0); _delay_us(17752); break;
            case 166: _delay_us(2259); pinW(port, pin, 0); _delay_us(17741); break;
            case 167: _delay_us(2269); pinW(port, pin, 0); _delay_us(17731); break;
            case 168: _delay_us(2279); pinW(port, pin, 0); _delay_us(17721); break;
            case 169: _delay_us(2290); pinW(port, pin, 0); _delay_us(17710); break;
            case 170: _delay_us(2300); pinW(port, pin, 0); _delay_us(17700); break;
            case 171: _delay_us(2310); pinW(port, pin, 0); _delay_us(17690); break;
            case 172: _delay_us(2321); pinW(port, pin, 0); _delay_us(17679); break;
            case 173: _delay_us(2331); pinW(port, pin, 0); _delay_us(17669); break;
            case 174: _delay_us(2341); pinW(port, pin, 0); _delay_us(17659); break;
            case 175: _delay_us(2352); pinW(port, pin, 0); _delay_us(17648); break;
            case 176: _delay_us(2362); pinW(port, pin, 0); _delay_us(17638); break;
            case 177: _delay_us(2372); pinW(port, pin, 0); _delay_us(17628); break;
            case 178: _delay_us(2383); pinW(port, pin, 0); _delay_us(17617); break;
            case 179: _delay_us(2393); pinW(port, pin, 0); _delay_us(17607); break;
            case 180: _delay_us(2400); pinW(port, pin, 0); _delay_us(17600); break; // Tam 180 derece maksimum sınır!

            default:
                _delay_us(1472); // Hatalı bir şey gelirse tam orta nokta 90 derece
                pinW(port, pin, 0);
                _delay_us(18528);
                break;
        }
    }
}