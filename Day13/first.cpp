#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <regex>
#include <map>
#include <queue>
#include <set>

class obje {
public:
    int prizeX, prizeY;
    int Acount, Bcount;

    obje(int prizeX, int prizeY) : prizeX(prizeX), prizeY(prizeY) {
        Acount = 0;
        Bcount = 0;
    }
};

int findlow(int prizeX, int prizeY, int AX, int AY, int BX, int BY) {
    std::queue<obje> q;
    std::set<std::pair<int, int>> visited; 

    obje start(prizeX, prizeY);
    q.push(start);
    visited.insert({prizeX, prizeY});

    while (!q.empty()) {
        obje ob = q.front();
        q.pop();

        if (ob.prizeX == 0 && ob.prizeY == 0) {
            return ob.Acount * 3 + ob.Bcount;
        }

        if (ob.prizeX < 0 || ob.prizeY < 0) continue;

        obje obA = ob;
        obA.Acount++;
        obA.prizeX -= AX;
        obA.prizeY -= AY;

        if (visited.find({obA.prizeX, obA.prizeY}) == visited.end()) {
            visited.insert({obA.prizeX, obA.prizeY});
            q.push(obA);
        }

        obje obB = ob;
        obB.Bcount++;
        obB.prizeX -= BX;
        obB.prizeY -= BY;

        if (visited.find({obB.prizeX, obB.prizeY}) == visited.end()) {
            visited.insert({obB.prizeX, obB.prizeY});
            q.push(obB);
        }
    }

    return 0; 
}

int main() {

    std::string s = R"(Button A: X+26, Y+56
Button B: X+43, Y+22
Prize: X=6138, Y=6756

Button A: X+50, Y+14
Button B: X+18, Y+67
Prize: X=6652, Y=8473

Button A: X+24, Y+97
Button B: X+48, Y+13
Prize: X=6624, Y=10120

Button A: X+41, Y+16
Button B: X+30, Y+47
Prize: X=16792, Y=7758

Button A: X+63, Y+14
Button B: X+14, Y+53
Prize: X=10609, Y=16459

Button A: X+17, Y+51
Button B: X+69, Y+34
Prize: X=6022, Y=16887

Button A: X+12, Y+54
Button B: X+36, Y+27
Prize: X=2052, Y=3024

Button A: X+45, Y+11
Button B: X+27, Y+72
Prize: X=13319, Y=7369

Button A: X+11, Y+63
Button B: X+73, Y+62
Prize: X=3841, Y=8467

Button A: X+60, Y+77
Button B: X+95, Y+30
Prize: X=8180, Y=5718

Button A: X+65, Y+32
Button B: X+14, Y+56
Prize: X=11771, Y=5912

Button A: X+15, Y+65
Button B: X+81, Y+22
Prize: X=1778, Y=3006

Button A: X+19, Y+97
Button B: X+98, Y+69
Prize: X=10982, Y=15091

Button A: X+74, Y+27
Button B: X+17, Y+55
Prize: X=5004, Y=5144

Button A: X+31, Y+65
Button B: X+58, Y+26
Prize: X=9830, Y=12002

Button A: X+22, Y+48
Button B: X+51, Y+16
Prize: X=13119, Y=18688

Button A: X+81, Y+24
Button B: X+12, Y+59
Prize: X=6491, Y=5470

Button A: X+90, Y+51
Button B: X+30, Y+59
Prize: X=8370, Y=5625

Button A: X+19, Y+59
Button B: X+50, Y+22
Prize: X=17265, Y=18613

Button A: X+63, Y+24
Button B: X+23, Y+67
Prize: X=17826, Y=2440

Button A: X+66, Y+13
Button B: X+20, Y+67
Prize: X=2354, Y=17453

Button A: X+47, Y+21
Button B: X+11, Y+77
Prize: X=4544, Y=6860

Button A: X+20, Y+56
Button B: X+64, Y+29
Prize: X=17268, Y=1378

Button A: X+25, Y+11
Button B: X+38, Y+72
Prize: X=3687, Y=2805

Button A: X+24, Y+43
Button B: X+37, Y+12
Prize: X=13751, Y=5223

Button A: X+69, Y+18
Button B: X+74, Y+81
Prize: X=12179, Y=7866

Button A: X+18, Y+77
Button B: X+75, Y+34
Prize: X=1485, Y=2050

Button A: X+79, Y+47
Button B: X+46, Y+89
Prize: X=8102, Y=6361

Button A: X+11, Y+77
Button B: X+53, Y+64
Prize: X=3163, Y=6177

Button A: X+44, Y+94
Button B: X+99, Y+50
Prize: X=11154, Y=8648

Button A: X+43, Y+48
Button B: X+47, Y+13
Prize: X=5939, Y=2762

Button A: X+20, Y+81
Button B: X+88, Y+79
Prize: X=8636, Y=12229

Button A: X+20, Y+66
Button B: X+29, Y+16
Prize: X=1115, Y=2484

Button A: X+11, Y+57
Button B: X+85, Y+37
Prize: X=9455, Y=13789

Button A: X+57, Y+37
Button B: X+27, Y+53
Prize: X=5349, Y=3685

Button A: X+20, Y+39
Button B: X+60, Y+30
Prize: X=4800, Y=7433

Button A: X+71, Y+97
Button B: X+67, Y+13
Prize: X=4656, Y=2984

Button A: X+27, Y+55
Button B: X+65, Y+31
Prize: X=10253, Y=8793

Button A: X+32, Y+12
Button B: X+18, Y+37
Prize: X=6016, Y=14600

Button A: X+38, Y+12
Button B: X+68, Y+83
Prize: X=6976, Y=8171

Button A: X+11, Y+48
Button B: X+39, Y+13
Prize: X=12094, Y=7506

Button A: X+42, Y+15
Button B: X+19, Y+77
Prize: X=4619, Y=5371

Button A: X+25, Y+40
Button B: X+41, Y+18
Prize: X=2766, Y=14758

Button A: X+11, Y+67
Button B: X+40, Y+14
Prize: X=2225, Y=19517

Button A: X+55, Y+19
Button B: X+13, Y+50
Prize: X=8820, Y=7076

Button A: X+13, Y+33
Button B: X+72, Y+46
Prize: X=17473, Y=8055

Button A: X+62, Y+28
Button B: X+14, Y+45
Prize: X=4660, Y=3845

Button A: X+20, Y+65
Button B: X+66, Y+18
Prize: X=5990, Y=19250

Button A: X+65, Y+28
Button B: X+20, Y+96
Prize: X=2160, Y=9232

Button A: X+94, Y+44
Button B: X+35, Y+95
Prize: X=3643, Y=5243

Button A: X+72, Y+23
Button B: X+17, Y+54
Prize: X=7200, Y=10004

Button A: X+58, Y+13
Button B: X+40, Y+71
Prize: X=4478, Y=1562

Button A: X+26, Y+99
Button B: X+53, Y+20
Prize: X=5494, Y=5284

Button A: X+17, Y+30
Button B: X+50, Y+22
Prize: X=16167, Y=17286

Button A: X+40, Y+16
Button B: X+15, Y+29
Prize: X=13485, Y=19231

Button A: X+71, Y+72
Button B: X+82, Y+17
Prize: X=12771, Y=6600

Button A: X+28, Y+63
Button B: X+55, Y+15
Prize: X=15036, Y=5951

Button A: X+41, Y+18
Button B: X+22, Y+65
Prize: X=18154, Y=1681

Button A: X+74, Y+18
Button B: X+54, Y+78
Prize: X=5322, Y=3954

Button A: X+17, Y+22
Button B: X+75, Y+29
Prize: X=5043, Y=2783

Button A: X+36, Y+11
Button B: X+34, Y+54
Prize: X=1068, Y=7138

Button A: X+66, Y+25
Button B: X+13, Y+37
Prize: X=9160, Y=1558

Button A: X+11, Y+37
Button B: X+82, Y+57
Prize: X=6296, Y=10153

Button A: X+22, Y+68
Button B: X+30, Y+27
Prize: X=4304, Y=7585

Button A: X+33, Y+18
Button B: X+18, Y+34
Prize: X=3792, Y=2818

Button A: X+27, Y+42
Button B: X+49, Y+22
Prize: X=1945, Y=2158

Button A: X+36, Y+90
Button B: X+77, Y+15
Prize: X=6692, Y=5370

Button A: X+35, Y+17
Button B: X+16, Y+42
Prize: X=5524, Y=7192

Button A: X+64, Y+89
Button B: X+94, Y+16
Prize: X=1422, Y=945

Button A: X+26, Y+99
Button B: X+91, Y+82
Prize: X=8840, Y=10384

Button A: X+28, Y+70
Button B: X+93, Y+12
Prize: X=7537, Y=3628

Button A: X+71, Y+30
Button B: X+27, Y+44
Prize: X=5916, Y=2956

Button A: X+19, Y+49
Button B: X+34, Y+21
Prize: X=3678, Y=10742

Button A: X+40, Y+94
Button B: X+36, Y+13
Prize: X=6168, Y=7478

Button A: X+11, Y+77
Button B: X+96, Y+56
Prize: X=6140, Y=7252

Button A: X+63, Y+12
Button B: X+24, Y+74
Prize: X=15134, Y=19126

Button A: X+55, Y+35
Button B: X+26, Y+88
Prize: X=4764, Y=4032

Button A: X+44, Y+98
Button B: X+77, Y+53
Prize: X=4917, Y=5619

Button A: X+32, Y+12
Button B: X+13, Y+26
Prize: X=5179, Y=2646

Button A: X+39, Y+85
Button B: X+56, Y+13
Prize: X=4943, Y=13926

Button A: X+16, Y+62
Button B: X+56, Y+20
Prize: X=9688, Y=6300

Button A: X+61, Y+73
Button B: X+99, Y+12
Prize: X=11276, Y=5828

Button A: X+40, Y+17
Button B: X+48, Y+70
Prize: X=3672, Y=10447

Button A: X+12, Y+49
Button B: X+81, Y+35
Prize: X=19253, Y=7144

Button A: X+11, Y+44
Button B: X+38, Y+22
Prize: X=1272, Y=1188

Button A: X+31, Y+56
Button B: X+53, Y+13
Prize: X=5317, Y=6047

Button A: X+38, Y+60
Button B: X+44, Y+14
Prize: X=16404, Y=4916

Button A: X+55, Y+11
Button B: X+13, Y+31
Prize: X=14720, Y=2090

Button A: X+12, Y+61
Button B: X+45, Y+12
Prize: X=1482, Y=4499

Button A: X+49, Y+14
Button B: X+12, Y+23
Prize: X=7777, Y=13287

Button A: X+37, Y+19
Button B: X+39, Y+61
Prize: X=17118, Y=6298

Button A: X+54, Y+16
Button B: X+14, Y+68
Prize: X=12658, Y=12796

Button A: X+24, Y+43
Button B: X+30, Y+13
Prize: X=3164, Y=8597

Button A: X+13, Y+44
Button B: X+56, Y+14
Prize: X=12423, Y=6708

Button A: X+33, Y+15
Button B: X+32, Y+58
Prize: X=10165, Y=6867

Button A: X+77, Y+29
Button B: X+16, Y+52
Prize: X=19789, Y=19453

Button A: X+34, Y+18
Button B: X+34, Y+64
Prize: X=10444, Y=5422

Button A: X+31, Y+79
Button B: X+40, Y+12
Prize: X=5026, Y=8278

Button A: X+62, Y+18
Button B: X+23, Y+70
Prize: X=5040, Y=10172

Button A: X+74, Y+28
Button B: X+16, Y+59
Prize: X=8572, Y=18354

Button A: X+21, Y+60
Button B: X+27, Y+12
Prize: X=9692, Y=2432

Button A: X+37, Y+19
Button B: X+46, Y+85
Prize: X=6962, Y=8915

Button A: X+15, Y+34
Button B: X+52, Y+37
Prize: X=15751, Y=14194

Button A: X+51, Y+18
Button B: X+13, Y+56
Prize: X=5920, Y=7344

Button A: X+42, Y+12
Button B: X+25, Y+77
Prize: X=18568, Y=18120

Button A: X+53, Y+22
Button B: X+37, Y+65
Prize: X=11761, Y=6432

Button A: X+84, Y+25
Button B: X+15, Y+72
Prize: X=17846, Y=11078

Button A: X+30, Y+83
Button B: X+67, Y+13
Prize: X=16115, Y=16095

Button A: X+25, Y+93
Button B: X+88, Y+30
Prize: X=5355, Y=9513

Button A: X+38, Y+19
Button B: X+33, Y+64
Prize: X=7008, Y=9739

Button A: X+72, Y+93
Button B: X+34, Y+13
Prize: X=4500, Y=3030

Button A: X+99, Y+48
Button B: X+53, Y+86
Prize: X=13843, Y=11536

Button A: X+51, Y+18
Button B: X+31, Y+73
Prize: X=14911, Y=15403

Button A: X+51, Y+28
Button B: X+16, Y+37
Prize: X=3217, Y=5994

Button A: X+13, Y+97
Button B: X+74, Y+43
Prize: X=7722, Y=11285

Button A: X+53, Y+25
Button B: X+14, Y+31
Prize: X=2836, Y=1242

Button A: X+59, Y+19
Button B: X+58, Y+79
Prize: X=2176, Y=1123

Button A: X+94, Y+41
Button B: X+23, Y+89
Prize: X=2874, Y=7571

Button A: X+96, Y+40
Button B: X+46, Y+73
Prize: X=10802, Y=7031

Button A: X+53, Y+16
Button B: X+18, Y+72
Prize: X=2715, Y=10624

Button A: X+68, Y+71
Button B: X+82, Y+23
Prize: X=10736, Y=6075

Button A: X+54, Y+44
Button B: X+22, Y+70
Prize: X=4660, Y=5880

Button A: X+73, Y+14
Button B: X+20, Y+78
Prize: X=13374, Y=2486

Button A: X+18, Y+97
Button B: X+62, Y+51
Prize: X=1428, Y=6846

Button A: X+14, Y+48
Button B: X+80, Y+37
Prize: X=7580, Y=6931

Button A: X+69, Y+44
Button B: X+25, Y+96
Prize: X=6932, Y=9384

Button A: X+22, Y+43
Button B: X+28, Y+17
Prize: X=13126, Y=18969

Button A: X+84, Y+69
Button B: X+18, Y+84
Prize: X=3798, Y=9003

Button A: X+94, Y+94
Button B: X+93, Y+18
Prize: X=11605, Y=7780

Button A: X+15, Y+65
Button B: X+71, Y+11
Prize: X=2252, Y=11182

Button A: X+24, Y+64
Button B: X+50, Y+20
Prize: X=500, Y=18040

Button A: X+72, Y+24
Button B: X+13, Y+43
Prize: X=17582, Y=19106

Button A: X+51, Y+22
Button B: X+28, Y+64
Prize: X=4841, Y=4674

Button A: X+43, Y+14
Button B: X+22, Y+53
Prize: X=19232, Y=4535

Button A: X+31, Y+12
Button B: X+26, Y+69
Prize: X=8024, Y=395

Button A: X+96, Y+39
Button B: X+18, Y+70
Prize: X=6216, Y=4782

Button A: X+33, Y+54
Button B: X+25, Y+12
Prize: X=1913, Y=1338

Button A: X+86, Y+13
Button B: X+23, Y+67
Prize: X=6382, Y=1727

Button A: X+12, Y+30
Button B: X+55, Y+43
Prize: X=3279, Y=2811

Button A: X+19, Y+36
Button B: X+53, Y+25
Prize: X=7110, Y=1542

Button A: X+20, Y+73
Button B: X+34, Y+11
Prize: X=4510, Y=8103

Button A: X+12, Y+46
Button B: X+77, Y+19
Prize: X=15858, Y=4320

Button A: X+12, Y+73
Button B: X+57, Y+15
Prize: X=16058, Y=1135

Button A: X+23, Y+90
Button B: X+80, Y+19
Prize: X=8661, Y=7721

Button A: X+83, Y+30
Button B: X+12, Y+55
Prize: X=12158, Y=350

Button A: X+16, Y+32
Button B: X+42, Y+19
Prize: X=2470, Y=3445

Button A: X+17, Y+51
Button B: X+61, Y+11
Prize: X=12670, Y=17962

Button A: X+38, Y+13
Button B: X+35, Y+62
Prize: X=11218, Y=5031

Button A: X+69, Y+34
Button B: X+13, Y+50
Prize: X=18889, Y=3914

Button A: X+46, Y+25
Button B: X+14, Y+36
Prize: X=1274, Y=2623

Button A: X+57, Y+19
Button B: X+33, Y+68
Prize: X=13340, Y=2367

Button A: X+16, Y+58
Button B: X+41, Y+19
Prize: X=1688, Y=7306

Button A: X+96, Y+56
Button B: X+28, Y+79
Prize: X=9128, Y=6202

Button A: X+22, Y+69
Button B: X+98, Y+76
Prize: X=5638, Y=8891

Button A: X+63, Y+38
Button B: X+19, Y+39
Prize: X=19077, Y=13237

Button A: X+21, Y+76
Button B: X+74, Y+19
Prize: X=15231, Y=12261

Button A: X+11, Y+36
Button B: X+54, Y+17
Prize: X=15611, Y=18597

Button A: X+12, Y+23
Button B: X+52, Y+27
Prize: X=18580, Y=7041

Button A: X+28, Y+11
Button B: X+17, Y+34
Prize: X=3113, Y=1906

Button A: X+69, Y+12
Button B: X+23, Y+84
Prize: X=3527, Y=10676

Button A: X+86, Y+55
Button B: X+11, Y+41
Prize: X=567, Y=6679

Button A: X+17, Y+37
Button B: X+51, Y+16
Prize: X=17074, Y=5614

Button A: X+46, Y+14
Button B: X+20, Y+60
Prize: X=4574, Y=18886

Button A: X+62, Y+98
Button B: X+34, Y+14
Prize: X=1600, Y=1456

Button A: X+24, Y+53
Button B: X+51, Y+26
Prize: X=4443, Y=4874

Button A: X+31, Y+78
Button B: X+60, Y+11
Prize: X=15539, Y=2767

Button A: X+14, Y+48
Button B: X+79, Y+46
Prize: X=227, Y=1930

Button A: X+55, Y+17
Button B: X+14, Y+72
Prize: X=16521, Y=9685

Button A: X+41, Y+16
Button B: X+21, Y+86
Prize: X=3856, Y=8196

Button A: X+51, Y+32
Button B: X+18, Y+50
Prize: X=2016, Y=2310

Button A: X+80, Y+35
Button B: X+11, Y+51
Prize: X=10378, Y=9793

Button A: X+61, Y+61
Button B: X+13, Y+95
Prize: X=1876, Y=9092

Button A: X+93, Y+15
Button B: X+35, Y+61
Prize: X=8297, Y=5047

Button A: X+34, Y+72
Button B: X+33, Y+19
Prize: X=3473, Y=4149

Button A: X+24, Y+68
Button B: X+44, Y+16
Prize: X=18976, Y=488

Button A: X+71, Y+16
Button B: X+20, Y+63
Prize: X=1235, Y=2852

Button A: X+97, Y+45
Button B: X+39, Y+91
Prize: X=8747, Y=10255

Button A: X+40, Y+14
Button B: X+16, Y+54
Prize: X=8664, Y=13576

Button A: X+80, Y+92
Button B: X+67, Y+19
Prize: X=6720, Y=3084

Button A: X+11, Y+61
Button B: X+78, Y+20
Prize: X=4170, Y=14874

Button A: X+35, Y+13
Button B: X+14, Y+31
Prize: X=1432, Y=10269

Button A: X+24, Y+67
Button B: X+98, Y+54
Prize: X=11524, Y=10652

Button A: X+20, Y+44
Button B: X+62, Y+17
Prize: X=1254, Y=15393

Button A: X+42, Y+18
Button B: X+12, Y+17
Prize: X=10538, Y=13796

Button A: X+30, Y+70
Button B: X+43, Y+11
Prize: X=9020, Y=2580

Button A: X+68, Y+34
Button B: X+18, Y+40
Prize: X=3326, Y=11222

Button A: X+34, Y+56
Button B: X+27, Y+11
Prize: X=7573, Y=13367

Button A: X+18, Y+60
Button B: X+44, Y+19
Prize: X=1358, Y=9236

Button A: X+97, Y+28
Button B: X+28, Y+95
Prize: X=3458, Y=7517

Button A: X+17, Y+33
Button B: X+41, Y+26
Prize: X=8162, Y=14905

Button A: X+19, Y+57
Button B: X+47, Y+12
Prize: X=11573, Y=8006

Button A: X+11, Y+48
Button B: X+84, Y+42
Prize: X=9256, Y=2948

Button A: X+32, Y+15
Button B: X+27, Y+41
Prize: X=1377, Y=11431

Button A: X+74, Y+33
Button B: X+15, Y+46
Prize: X=19289, Y=16719

Button A: X+70, Y+21
Button B: X+28, Y+76
Prize: X=12772, Y=12688

Button A: X+15, Y+36
Button B: X+66, Y+25
Prize: X=2315, Y=3139

Button A: X+48, Y+11
Button B: X+61, Y+57
Prize: X=7333, Y=4821

Button A: X+47, Y+19
Button B: X+18, Y+30
Prize: X=5328, Y=13852

Button A: X+74, Y+24
Button B: X+12, Y+71
Prize: X=4092, Y=624

Button A: X+46, Y+74
Button B: X+94, Y+45
Prize: X=7412, Y=6719

Button A: X+36, Y+11
Button B: X+27, Y+61
Prize: X=5525, Y=18218

Button A: X+15, Y+93
Button B: X+92, Y+87
Prize: X=6117, Y=6021

Button A: X+19, Y+90
Button B: X+37, Y+16
Prize: X=4146, Y=8172

Button A: X+56, Y+21
Button B: X+14, Y+44
Prize: X=9594, Y=9114

Button A: X+19, Y+52
Button B: X+44, Y+20
Prize: X=17937, Y=4380

Button A: X+11, Y+72
Button B: X+53, Y+15
Prize: X=14734, Y=6206

Button A: X+33, Y+16
Button B: X+18, Y+38
Prize: X=19454, Y=1148

Button A: X+41, Y+15
Button B: X+27, Y+60
Prize: X=19296, Y=17675

Button A: X+11, Y+29
Button B: X+32, Y+24
Prize: X=6266, Y=16302

Button A: X+37, Y+87
Button B: X+79, Y+43
Prize: X=5631, Y=3533

Button A: X+67, Y+27
Button B: X+21, Y+68
Prize: X=392, Y=6801

Button A: X+13, Y+51
Button B: X+55, Y+26
Prize: X=11979, Y=10278

Button A: X+15, Y+49
Button B: X+42, Y+21
Prize: X=6425, Y=13843

Button A: X+18, Y+72
Button B: X+77, Y+13
Prize: X=11325, Y=14395

Button A: X+27, Y+67
Button B: X+47, Y+16
Prize: X=17684, Y=13772

Button A: X+55, Y+11
Button B: X+31, Y+82
Prize: X=4588, Y=8526

Button A: X+21, Y+60
Button B: X+65, Y+17
Prize: X=11626, Y=15430

Button A: X+87, Y+34
Button B: X+11, Y+57
Prize: X=8988, Y=836

Button A: X+81, Y+35
Button B: X+34, Y+89
Prize: X=5733, Y=9165

Button A: X+28, Y+83
Button B: X+84, Y+24
Prize: X=3528, Y=5958

Button A: X+29, Y+54
Button B: X+89, Y+22
Prize: X=4532, Y=3696

Button A: X+12, Y+72
Button B: X+67, Y+16
Prize: X=1235, Y=7208

Button A: X+47, Y+36
Button B: X+18, Y+71
Prize: X=3381, Y=4821

Button A: X+23, Y+59
Button B: X+31, Y+12
Prize: X=15730, Y=10712

Button A: X+20, Y+58
Button B: X+39, Y+31
Prize: X=3973, Y=6021

Button A: X+15, Y+35
Button B: X+59, Y+21
Prize: X=13645, Y=8005

Button A: X+19, Y+58
Button B: X+43, Y+18
Prize: X=6405, Y=3158

Button A: X+14, Y+27
Button B: X+91, Y+56
Prize: X=3458, Y=3801

Button A: X+72, Y+93
Button B: X+53, Y+21
Prize: X=6157, Y=7146

Button A: X+70, Y+38
Button B: X+50, Y+94
Prize: X=6990, Y=9210

Button A: X+76, Y+68
Button B: X+20, Y+81
Prize: X=6984, Y=6943

Button A: X+70, Y+42
Button B: X+23, Y+48
Prize: X=9428, Y=6632

Button A: X+68, Y+13
Button B: X+98, Y+87
Prize: X=12274, Y=8149

Button A: X+17, Y+42
Button B: X+26, Y+11
Prize: X=18104, Y=4889

Button A: X+97, Y+15
Button B: X+50, Y+84
Prize: X=5224, Y=2562

Button A: X+76, Y+21
Button B: X+19, Y+72
Prize: X=19158, Y=10553

Button A: X+11, Y+43
Button B: X+38, Y+11
Prize: X=18639, Y=14854

Button A: X+11, Y+49
Button B: X+81, Y+26
Prize: X=19283, Y=16139

Button A: X+16, Y+50
Button B: X+76, Y+34
Prize: X=10600, Y=9642

Button A: X+90, Y+35
Button B: X+42, Y+59
Prize: X=6906, Y=5587

Button A: X+39, Y+17
Button B: X+13, Y+60
Prize: X=10624, Y=7169

Button A: X+54, Y+63
Button B: X+47, Y+11
Prize: X=4465, Y=3412

Button A: X+21, Y+81
Button B: X+72, Y+16
Prize: X=12071, Y=12499

Button A: X+37, Y+18
Button B: X+13, Y+45
Prize: X=1827, Y=10106

Button A: X+20, Y+83
Button B: X+69, Y+50
Prize: X=4672, Y=8044

Button A: X+44, Y+16
Button B: X+36, Y+61
Prize: X=19592, Y=7020

Button A: X+72, Y+31
Button B: X+17, Y+64
Prize: X=12437, Y=4069

Button A: X+47, Y+46
Button B: X+15, Y+99
Prize: X=2447, Y=3997

Button A: X+39, Y+88
Button B: X+58, Y+41
Prize: X=8132, Y=11429

Button A: X+70, Y+12
Button B: X+17, Y+56
Prize: X=13605, Y=15544

Button A: X+17, Y+62
Button B: X+74, Y+12
Prize: X=15616, Y=6784

Button A: X+52, Y+25
Button B: X+30, Y+58
Prize: X=5746, Y=14562

Button A: X+92, Y+22
Button B: X+18, Y+99
Prize: X=6256, Y=10208

Button A: X+57, Y+75
Button B: X+93, Y+39
Prize: X=13887, Y=10269

Button A: X+63, Y+18
Button B: X+34, Y+68
Prize: X=6181, Y=7070

Button A: X+35, Y+51
Button B: X+24, Y+11
Prize: X=769, Y=16961

Button A: X+37, Y+23
Button B: X+34, Y+74
Prize: X=1678, Y=3422

Button A: X+60, Y+40
Button B: X+15, Y+40
Prize: X=6045, Y=6760

Button A: X+17, Y+41
Button B: X+35, Y+18
Prize: X=10235, Y=15742

Button A: X+17, Y+83
Button B: X+74, Y+33
Prize: X=2837, Y=4659

Button A: X+19, Y+35
Button B: X+45, Y+20
Prize: X=8289, Y=11000

Button A: X+75, Y+13
Button B: X+45, Y+61
Prize: X=2910, Y=2792

Button A: X+17, Y+35
Button B: X+52, Y+21
Prize: X=8192, Y=9720

Button A: X+62, Y+86
Button B: X+52, Y+18
Prize: X=5630, Y=4724

Button A: X+34, Y+13
Button B: X+38, Y+64
Prize: X=8740, Y=2019

Button A: X+53, Y+17
Button B: X+15, Y+32
Prize: X=19144, Y=8275

Button A: X+15, Y+73
Button B: X+87, Y+72
Prize: X=1572, Y=5542

Button A: X+17, Y+56
Button B: X+62, Y+17
Prize: X=2779, Y=6232

Button A: X+87, Y+21
Button B: X+65, Y+65
Prize: X=9471, Y=4653

Button A: X+17, Y+32
Button B: X+61, Y+29
Prize: X=15105, Y=17379

Button A: X+38, Y+54
Button B: X+33, Y+12
Prize: X=14329, Y=14654

Button A: X+37, Y+11
Button B: X+12, Y+43
Prize: X=15378, Y=16443

Button A: X+28, Y+51
Button B: X+46, Y+24
Prize: X=8688, Y=5189

Button A: X+16, Y+33
Button B: X+55, Y+29
Prize: X=12145, Y=9115

Button A: X+61, Y+29
Button B: X+25, Y+64
Prize: X=7997, Y=17422

Button A: X+17, Y+59
Button B: X+80, Y+37
Prize: X=10337, Y=17077

Button A: X+15, Y+37
Button B: X+65, Y+32
Prize: X=6245, Y=3726

Button A: X+73, Y+31
Button B: X+11, Y+37
Prize: X=3352, Y=5144

Button A: X+56, Y+23
Button B: X+22, Y+67
Prize: X=11416, Y=16285

Button A: X+53, Y+22
Button B: X+44, Y+75
Prize: X=1735, Y=3378

Button A: X+20, Y+82
Button B: X+59, Y+50
Prize: X=1694, Y=5794

Button A: X+33, Y+52
Button B: X+67, Y+33
Prize: X=4946, Y=3294

Button A: X+79, Y+43
Button B: X+11, Y+36
Prize: X=11247, Y=18665

Button A: X+37, Y+79
Button B: X+73, Y+46
Prize: X=7422, Y=6069

Button A: X+43, Y+15
Button B: X+23, Y+57
Prize: X=2286, Y=5558

Button A: X+11, Y+72
Button B: X+85, Y+23
Prize: X=8324, Y=14662

Button A: X+31, Y+53
Button B: X+45, Y+20
Prize: X=18860, Y=15635

Button A: X+17, Y+57
Button B: X+37, Y+12
Prize: X=18872, Y=12272

Button A: X+33, Y+17
Button B: X+15, Y+36
Prize: X=2060, Y=19691

Button A: X+14, Y+30
Button B: X+52, Y+32
Prize: X=17606, Y=7094

Button A: X+40, Y+12
Button B: X+61, Y+99
Prize: X=6012, Y=9228

Button A: X+76, Y+53
Button B: X+22, Y+69
Prize: X=7340, Y=7265

Button A: X+12, Y+81
Button B: X+92, Y+47
Prize: X=8148, Y=10227

Button A: X+11, Y+41
Button B: X+71, Y+14
Prize: X=9518, Y=12620

Button A: X+43, Y+18
Button B: X+30, Y+42
Prize: X=1034, Y=1110

Button A: X+69, Y+14
Button B: X+16, Y+74
Prize: X=19169, Y=7540

Button A: X+55, Y+24
Button B: X+21, Y+63
Prize: X=10819, Y=17399

Button A: X+20, Y+38
Button B: X+51, Y+29
Prize: X=2856, Y=10222

Button A: X+14, Y+57
Button B: X+82, Y+35
Prize: X=5562, Y=8359

Button A: X+57, Y+24
Button B: X+36, Y+66
Prize: X=19544, Y=18206

Button A: X+65, Y+20
Button B: X+12, Y+40
Prize: X=16445, Y=12260

Button A: X+24, Y+48
Button B: X+31, Y+11
Prize: X=6498, Y=3946

Button A: X+13, Y+62
Button B: X+45, Y+15
Prize: X=2755, Y=4955

Button A: X+65, Y+62
Button B: X+21, Y+86
Prize: X=4790, Y=10836

Button A: X+67, Y+15
Button B: X+76, Y+98
Prize: X=8587, Y=9859

Button A: X+72, Y+56
Button B: X+13, Y+60
Prize: X=5617, Y=7412

Button A: X+67, Y+28
Button B: X+27, Y+90
Prize: X=7054, Y=10426

Button A: X+11, Y+54
Button B: X+68, Y+20
Prize: X=9547, Y=2670

Button A: X+82, Y+43
Button B: X+18, Y+63
Prize: X=5786, Y=7319

Button A: X+25, Y+64
Button B: X+92, Y+33
Prize: X=3685, Y=3358

Button A: X+33, Y+41
Button B: X+71, Y+25
Prize: X=9654, Y=5926

Button A: X+16, Y+50
Button B: X+66, Y+30
Prize: X=10760, Y=5870

Button A: X+36, Y+89
Button B: X+88, Y+52
Prize: X=3284, Y=7291

Button A: X+33, Y+14
Button B: X+35, Y+72
Prize: X=862, Y=3798

Button A: X+57, Y+19
Button B: X+21, Y+65
Prize: X=19460, Y=9118

Button A: X+44, Y+21
Button B: X+14, Y+49
Prize: X=4860, Y=1985

Button A: X+24, Y+48
Button B: X+46, Y+29
Prize: X=16950, Y=6253

Button A: X+78, Y+81
Button B: X+18, Y+92
Prize: X=4806, Y=5504

Button A: X+12, Y+48
Button B: X+52, Y+21
Prize: X=6772, Y=15986

Button A: X+63, Y+38
Button B: X+22, Y+51
Prize: X=1258, Y=14602)";
    
// s = R"(Button A: X+94, Y+34
// Button B: X+22, Y+67
// Prize: X=8400, Y=5400

// Button A: X+26, Y+66
// Button B: X+67, Y+21
// Prize: X=12748, Y=12176

// Button A: X+17, Y+86
// Button B: X+84, Y+37
// Prize: X=7870, Y=6450

// Button A: X+69, Y+23
// Button B: X+27, Y+71
// Prize: X=18641, Y=10279)";


    std::stringstream stream(s);
    std::vector<std::vector<char>> map;
    std::string line;
    int result = 0;

    std::regex pattern(
        R"(Button A: X\+(\d+), Y\+(\d+)\s+Button B: X\+(\d+), Y\+(\d+)\s+Prize: X=(\d+), Y=(\d+))");

    auto matches_begin = std::sregex_iterator(s.begin(), s.end(), pattern);
    auto matches_end = std::sregex_iterator();

    for (std::sregex_iterator it = matches_begin; it != matches_end; ++it) {     
        std::smatch match = *it;
        //std::cout << std::stoi(match[5]) << std::stoi(match[6]) << std::stoi(match[1]) << std::stoi(match[2]) << std::stoi(match[3]) << std::stoi(match[4]) << std::endl;
        
        result += findlow(std::stoi(match[5]), std::stoi(match[6]), std::stoi(match[1]), std::stoi(match[2]), std::stoi(match[3]), std::stoi(match[4]));
        
        std::cout << "result = " << result << std::endl;
    }

    std::cout << "Final size: " << result << std::endl;
    return 0;
}

