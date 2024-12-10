/*

This program is to solve day 1 of "advent of code, (https://adventofcode.com/2024/day/1)"
From a list of numbers (My list: https://adventofcode.com/2024/day/1/input) I am to compare each number from each list.
I will take the smallest number from the left list, and the smallest number from the right list, and find the distance between the two.
For example: # in left list = 1, # in right list = 3, the distance between them is 2.
Then, do the same thing for the second smallest number in each list and so on.
At the end, each distance will be added together, resulting in the total distance between the left and right list: Then the problem is complete.

*/

/*

Roadmap V1:
?? Use includes() ?? to eliminate duplicates?...no
Use sort() to rearrange the numbers in ascending order.
Somehow pair two numbers, vectors and calling indexs? - subtract the two values, take absolute value to find distance.
Add the distances together
Output total

*/

  
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {

// Vector containing list1
vector<int> list1 = {
58990, 
26183,
48195,
20176,
26730,
85161,
96982,
87996,
39657,
78872,
34487,
29811,
21721,
26489,
42015,
27364,
74634,
97761,
55760,
73395,
70292,
23732,
35979,
39607,
47127,
92247,
46961,
91221,
78652,
37026,
11525,
44193,
25735,
69120,
48384,
31056,
21738,
58732,
24566,
44699,
14669,
67130,
43796,
23106,
96034,
35340,
71868,
33492,
51373,
99072,
39427,
92427,
33558,
89049,
43382,
48018,
11476,
61065,
40706,
38289,
61388,
10173,
73579,
79707,
28812,
86825,
20684,
51239,
81140,
76168,
99264,
26913,
94683,
78541,
67469,
21163,
17512,
98081,
59759,
14953,
44472,
95878,
45177,
94802,
78885,
32894,
81586,
20780,
45722,
57179,
58010,
18803,
31369,
47417,
23725,
24171,
41159,
86721,
42213,
67094,
42824,
75980,
57308,
71184,
92274,
17355,
21401,
41141,
26962,
58595,
74713,
64974,
81081,
65538,
79576,
45311,
53579,
27706,
33000,
94880,
58409,
62237,
95180,
75624,
87121,
20214,
37248,
81130,
93290,
48621,
55488,
30294,
18426,
61159,
66015,
22543,
22836,
75789,
89780,
80626,
79138,
32331,
64732,
64384,
98590,
32268,
76414,
14193,
59330,
34093,
83585,
95643,
61401,
38442,
93684,
26110,
15441,
92433,
28327,
21955,
49694,
25544,
84691,
79194,
16801,
49387,
26366,
98455,
80499,
68980,
93089,
90633,
48942,
52095,
35173,
50528,
48435,
78990,
57862,
83194,
11974,
55908,
67541,
44245,
20222,
35725,
23053,
67114,
39907,
26882,
83894,
48151,
45532,
54616,
29225,
23310,
27391,
81010,
37854,
12301,
60653,
39146,
19921,
20491,
20704,
89603,
48990,
17859,
91770,
26894,
71700,
53034,
64173,
35643,
47856,
41758,
25314,
89505,
33384,
90660,
36669,
77226,
22259,
30997,
49539,
61452,
44075,
53649,
60788,
47920,
19137,
41111,
68368,
13793,
60368,
26012,
51252,
43496,
65956,
18306,
84742,
10586,
69115,
30697,
73975,
98556,
72653,
92806,
70605,
79072,
28964,
64155,
33721,
72727,
42141,
38511,
73842,
39787,
67974,
39281,
78547,
86630,
65830,
30096,
83498,
79839,
36667,
34592,
55976,
29750,
83649,
49774,
45369,
25790,
28234,
64287,
14200,
67555,
23415,
51011,
35467,
88385,
64333,
93289,
78046,
61252,
56317,
39616,
40974,
89183,
71298,
40425,
44622,
16769,
50032,
94307,
67797,
53067,
44986,
97030,
16328,
28732,
14888,
76256,
12080,
20532,
65920,
82906,
68188,
35079,
40756,
96432,
24716,
97265,
40357,
78488,
58117,
53542,
80762,
73211,
34760,
72386,
24765,
77969,
42632,
73252,
43182,
22905,
71363,
18432,
80171,
80504,
87491,
94636,
90824,
76821,
97208,
39385,
25328,
47426,
41105,
86595,
25289,
14654,
98168,
52229,
77059,
33191,
56474,
84198,
30272,
95046,
46439,
42491,
17801,
25959,
14098,
67001,
53899,
35932,
60024,
51738,
44766,
99310,
57320,
91218,
79971,
61698,
15416,
60942,
33231,
82304,
13091,
34120,
62522,
51195,
86959,
13469,
26437,
17377,
20482,
58540,
44464,
76660,
65570,
68702,
13732,
37635,
40758,
88294,
57997,
15322,
15026,
10311,
40709,
49931,
78146,
35434,
21586,
14306,
54907,
39348,
34528,
85498,
97692,
93336,
93579,
70893,
98547,
99653,
97792,
94428,
47952,
46700,
82623,
51986,
95299,
90152,
21647,
51079,
76530,
16685,
15557,
27693,
30323,
33846,
36900,
51501,
79980,
96871,
94536,
13619,
12633,
29434,
37371,
30592,
61834,
37159,
76104,
42439,
12737,
40599,
78945,
26422,
40048,
33252,
64705,
38425,
34650,
77866,
42426,
86881,
31037,
24284,
31351,
11314,
40512,
61317,
86804,
93217,
54264,
71848,
41317,
20822,
13434,
75294,
45871,
94496,
79486,
73469,
73321,
84632,
13797,
81243,
49923,
17133,
70647,
77767,
11890,
99150,
22576,
57589,
19897,
17826,
81918,
10494,
95897,
25338,
55840,
47904,
64695,
97909,
49800,
23393,
44112,
34177,
45093,
13531,
11685,
61846,
19864,
71711,
41935,
30456,
93167,
54262,
16943,
56485,
83422,
27202,
32209,
18566,
71881,
90696,
83872,
33911,
79411,
39840,
18184,
72608,
75060,
99717,
27870,
79388,
88792,
87743,
21381,
16604,
79422,
99518,
43538,
59793,
51360,
71095,
54403,
87694,
99606,
56481,
52566,
85672,
10619,
49467,
74518,
84128,
21960,
20817,
41972,
41531,
52167,
33057,
20059,
58246,
96285,
58243,
20464,
43638,
61636,
95169,
39758,
81693,
67992,
87449,
26498,
70154,
39639,
43560,
71691,
97372,
86291,
93329,
37007,
50905,
95718,
53073,
95566,
37931,
44437,
69216,
68537,
89154,
83662,
96102,
93495,
37697,
51030,
43139,
89941,
74566,
71613,
53213,
35094,
25142,
97531,
36336,
56464,
98880,
40170,
68370,
62746,
14815,
82609,
37384,
79298,
15994,
24667,
62232,
76536,
22168,
47532,
83915,
53594,
44185,
33847,
80172,
92387,
77286,
58407,
51798,
85681,
98604,
23193,
42207,
29275,
38883,
64149,
94968,
88949,
23467,
24672,
31844,
63168,
18630,
25936,
99788,
76153,
64820,
48127,
42549,
36028,
65511,
83631,
30705,
63816,
49162,
64635,
35428,
85354,
43910,
34988,
59695,
56126,
79593,
60787,
65297,
71667,
78750,
28176,
30235,
29589,
94484,
28976,
10891,
82415,
17840,
12362,
44689,
32329,
36224,
49558,
36420,
24294,
55624,
40840,
51198,
87483,
93982,
50567,
61386,
65062,
20280,
19901,
75786,
79105,
52900,
15376,
24811,
75536,
49782,
61537,
75088,
60963,
65756,
77859,
34133,
99910,
98965,
65548,
85173,
97683,
74299,
58858,
80192,
34718,
16716,
70433,
47024,
30642,
94495,
87606,
18984,
44236,
91312,
91687,
54787,
55489,
55141,
27106,
68857,
85898,
94901,
50502,
98505,
30563,
66131,
20133,
83377,
33954,
97110,
14452,
17300,
18761,
74745,
91644,
28553,
94128,
33420,
92910,
37708,
61526,
76908,
10971,
63791,
99823,
36476,
47467,
86834,
67811,
66608,
57189,
90548,
27994,
41778,
81713,
29172,
97018,
16240,
40946,
12112,
11426,
84378,
82230,
80395,
12832,
81595,
46567,
73987,
29682,
26890,
60282,
29069,
51151,
23646,
97787,
25233,
22366,
18027,
74870,
65024,
95515,
27288,
53260,
47304,
79764,
13760,
52147,
97016,
72787,
82709,
79236,
67107,
51400,
68826,
58799,
81849,
50383,
35715,
36380,
74160,
22634,
80680,
55881,
67404,
40509,
71229,
74570,
32180,
17190,
20574,
39284,
87279,
52715,
23554,
32327,
69747,
62207,
83704,
75085,
29775,
60519,
43842,
40417,
36659,
15188,
79365,
18236,
44401,
28839,
70555,
16791,
85629,
74917,
56386,
70126,
71807,
21971,
23752,
45368,
29547,
35796,
56091,
85503,
40279,
62551,
25734,
95005,
51899,
22708,
41722,
71824,
59191,
82083,
78078,
15421,
31581,
76784,
65374,
45587,
64550,
97345,
36835,
15341,
45365,
61872,
64106,
64928,
47863,
27558,
82444,
74039,
53966,
21022,
49180,
52439,
86696,
25627,
29897,
29661,
98440,
20550,
49301,
67774,
19807,
91869,
74742,
30790,
29664,
55595,
25650,
81699,
88579,
85213,
50079,
38163,
11279,
66102,
73407,
16501,
97144,
28719,
48422,
27017,
30367,
58740,
82350,
19614,
75354,
14743,
71164,
40824,
29278,
78783,
15291,
99134,
51179,
61656,
36903,
42998,
32769,
38966,
61111,
43774,
83954,
62774,
23009,
83587,
11625,
85067,
79235,
27666,
71757,
63856,
74642,
84731,
82822,
98821,
18490,
31172,
50837,
16889,
47909,
27911,
92573,
99821,
16051,
90386,
15508,
94585,
42254,
88061,
48365,
48985,
68310,
51604,
37019,
25177,
12805,
44481,
66499,
58999,
81515,
13380,
92225,
85816,
66727,
12136,
41350,
76507,
14899,
70570,
87699,
86079,
75223,
86547,
39093,
49677,
62894,
71584,
63695,
20393,
61359,
80230,
35130,
29488,
31018,
71632,
21296,
46649,
40806,
85856,
17380,
21611,
88397,
84967,
75283,
86602,
97062,
74487,
98205,
52941,
16747
};

// Vector containing list2

vector<int> list2 = {
83989,
15707,
12659,
26012,
42699,
27706,
95631,
58243,
41171,
33231,
72728,
99268,
49694,
66506,
20464,
97109,
96288,
76904,
27706,
44236,
87279,
31037,
98965,
13469,
79924,
33911,
33231,
31037,
83821,
62907,
26730,
92319,
33249,
32589,
46622,
71217,
33911,
61515,
33911,
25959,
87970,
25959,
87726,
54813,
67811,
98556,
97692,
54616,
35614,
95208,
64273,
33911,
69302,
99150,
71632,
99449,
67811,
23675,
55203,
20464,
19960,
78890,
32327,
92137,
42327,
57070,
31037,
99150,
34779,
99150,
47093,
35996,
88397,
49558,
89113,
77443,
58592,
14460,
33911,
98556,
52439,
10311,
71299,
33231,
54616,
56495,
73037,
21728,
83302,
33911,
13033,
12885,
67973,
75886,
90560,
41980,
98556,
46022,
89733,
90269,
60452,
31037,
76611,
40177,
89725,
76918,
88969,
82206,
22168,
17840,
75610,
30283,
41393,
32330,
67054,
42563,
97692,
43952,
88917,
68771,
63351,
79967,
25790,
80977,
86053,
72368,
31153,
50096,
74779,
44148,
11750,
25790,
34334,
37275,
58595,
81784,
49558,
36896,
88896,
54609,
49500,
51373,
94408,
25959,
16398,
66516,
88397,
13469,
26730,
10311,
75324,
51373,
64620,
55909,
80680,
34957,
24332,
49558,
55141,
13469,
10893,
94388,
58243,
94680,
65278,
17840,
63022,
41105,
33231,
67811,
80086,
98556,
32327,
88397,
20464,
15228,
25959,
31641,
52439,
32327,
71373,
46627,
42458,
54654,
52439,
33787,
49558,
49561,
62721,
90072,
88397,
89230,
20122,
43083,
87279,
49694,
89779,
80680,
31037,
81934,
62188,
24897,
83997,
86255,
98554,
24418,
98965,
59190,
20464,
51373,
26730,
52439,
50150,
82272,
49558,
99150,
29584,
83762,
59580,
95080,
26730,
25562,
73630,
20464,
66511,
22708,
79857,
25790,
58595,
32327,
73043,
44410,
17840,
30684,
27410,
34148,
57009,
97692,
13469,
84529,
26730,
56357,
37394,
82636,
52439,
22168,
28561,
52439,
39685,
11939,
63109,
25959,
10311,
59988,
22708,
33231,
98965,
10956,
32926,
13469,
17840,
80730,
71632,
52439,
88397,
68049,
58595,
15526,
71632,
97528,
38418,
16314,
58595,
73805,
13874,
31037,
82623,
25790,
25790,
58243,
26012,
33922,
98965,
14155,
53761,
72609,
86600,
83714,
48045,
44236,
20464,
98556,
40331,
32327,
13469,
21621,
87043,
98965,
78348,
79597,
89331,
99527,
80769,
25959,
31216,
87498,
79221,
13469,
71544,
32327,
52439,
22198,
25959,
27706,
57909,
39786,
30532,
74875,
56553,
97463,
22294,
51373,
83968,
97636,
64391,
16844,
82974,
42642,
52439,
51474,
58243,
72049,
22168,
19806,
43498,
41878,
58243,
18510,
35469,
49558,
51373,
25959,
20464,
75836,
33802,
15427,
80312,
20464,
81018,
98491,
85675,
27870,
80680,
80680,
41607,
96386,
52439,
40744,
49888,
88615,
98965,
52439,
17840,
48015,
75523,
13940,
84186,
19307,
49558,
40468,
33231,
37067,
99150,
71471,
81211,
90298,
58595,
96220,
51351,
58243,
34401,
33911,
31037,
28713,
33231,
29170,
48144,
10311,
91054,
20464,
98780,
88397,
27870,
25959,
35778,
45153,
99353,
88397,
55141,
41466,
82131,
33911,
48569,
27870,
50901,
31037,
99784,
20464,
99150,
71632,
52439,
91785,
28237,
42531,
87524,
22708,
82459,
88865,
21625,
90706,
99864,
12061,
69728,
98965,
30876,
25959,
28621,
88397,
45861,
26012,
54616,
32327,
54616,
99150,
12715,
19467,
98965,
11465,
73667,
93792,
71632,
97728,
45461,
87279,
25790,
25199,
33231,
50988,
89998,
99150,
97850,
97692,
49027,
52439,
26600,
63580,
99150,
51373,
27200,
84636,
20464,
25105,
17840,
94183,
32327,
63872,
88397,
28919,
31037,
51920,
25790,
88397,
25790,
51373,
90162,
90672,
42099,
13062,
97692,
46800,
53468,
25361,
26730,
21976,
72722,
59416,
10311,
85339,
24358,
32327,
55141,
41087,
17199,
45735,
40395,
58243,
88397,
27870,
17840,
49694,
41105,
14196,
55742,
73366,
37656,
26012,
73066,
31037,
99150,
49558,
98973,
98556,
20464,
49901,
97692,
89520,
10982,
55119,
49558,
59553,
19448,
26008,
99150,
55141,
74946,
44236,
22708,
26012,
22708,
17840,
20464,
49694,
32327,
18697,
13469,
27870,
38781,
27637,
87874,
17840,
33231,
58243,
54616,
46916,
73325,
81944,
10311,
28597,
69556,
49558,
61122,
49558,
31037,
12449,
21688,
51863,
26012,
17442,
27540,
58564,
35284,
57059,
56170,
32327,
94226,
98965,
58595,
27040,
58243,
87286,
90197,
43748,
33036,
94048,
88397,
45535,
25959,
85393,
33911,
58243,
58607,
78378,
30297,
78352,
73399,
17315,
80561,
42345,
33715,
19951,
25866,
23986,
20824,
97692,
17840,
25959,
15790,
32327,
91777,
47770,
53322,
26572,
10311,
85092,
88397,
20464,
75320,
97692,
99882,
25790,
98556,
25959,
81474,
58243,
51155,
27870,
20464,
31037,
40873,
33911,
10311,
24730,
44653,
73550,
32327,
88747,
75785,
81864,
60634,
22708,
20464,
67458,
32327,
65630,
47192,
88894,
41006,
39491,
94108,
36428,
17527,
68759,
41105,
76956,
54824,
37327,
58595,
31289,
68656,
71632,
19390,
32327,
99150,
54606,
51373,
35414,
35321,
26012,
26012,
22708,
33911,
39188,
26012,
88397,
82623,
56497,
17840,
98556,
12520,
21364,
36318,
90378,
93019,
31037,
21075,
79772,
87279,
59761,
79864,
82100,
71632,
46099,
27870,
44803,
98556,
44210,
74306,
57620,
32130,
75904,
85542,
51725,
96787,
17840,
70330,
33911,
92432,
32752,
70578,
88397,
69589,
88397,
27870,
31037,
47321,
48665,
87279,
97692,
33911,
33911,
93040,
44915,
59401,
14448,
58254,
65394,
45500,
69327,
62022,
80680,
98965,
19302,
31037,
88397,
70635,
38650,
91671,
46037,
32533,
82532,
47202,
95535,
40500,
87279,
71899,
33797,
99150,
72908,
20464,
74639,
18271,
72651,
23737,
84997,
91743,
67811,
10311,
21028,
10311,
35661,
94117,
84101,
90550,
36583,
56756,
79873,
99150,
79991,
64939,
87279,
65726,
58243,
52917,
81384,
83604,
85489,
17840,
52439,
13469,
98965,
24098,
58828,
26012,
96638,
97982,
74245,
33231,
44767,
91430,
64938,
93877,
80434,
77500,
36198,
13732,
26984,
15983,
78450,
71632,
25959,
29710,
97692,
42756,
29891,
49043,
70394,
71632,
78588,
33231,
25959,
33911,
48000,
49558,
44236,
13469,
71632,
76323,
99580,
89698,
36191,
17142,
10392,
31339,
30887,
88397,
81078,
18344,
18477,
27870,
23095,
62592,
48017,
29519,
93885,
72179,
97966,
80680,
13469,
31892,
51728,
52509,
69664,
73109,
20464,
58243,
94017,
88397,
27283,
66651,
51373,
28778,
22708,
55346,
14804,
95049,
63155,
46060,
95729,
37142,
99274,
25959,
99150,
56253,
61593,
44236,
89414,
86495,
82113,
69762,
31480,
31037,
82638,
61538,
49345,
98413,
49558,
33911,
27063,
17644,
32390,
67811,
98950,
32327,
57405,
95357,
97963,
32327,
15331,
37870,
54616,
13469,
29401,
31037,
42872,
17840,
23132,
46418,
97692,
25959,
53267,
47433,
90511,
28443,
41105,
52439,
68587,
57839,
62521,
26237,
38113,
10311,
93821,
37160,
95594,
41334,
26730,
97692,
91177,
12317,
97692,
95869,
88541,
35793,
14442,
12198,
33231,
18567,
71632,
85081,
42408,
39223,
67811,
28337,
54616,
29814,
81703,
98556,
62042,
52439,
22168,
50515,
98013,
34159,
49694,
87023,
70325,
33231,
58243,
12338,
29925,
75634,
97692,
27870,
68857,
58243,
97537,
54482,
16585,
98650,
27870,
97692,
22168,
10181,
14118,
12130,
48734,
95568,
56369,
87279,
18858,
25790,
60825,
18987,
13241,
35829,
87296,
56008,
50028,
44236,
88397,
30962,
32327,
68650,
98984,
54616,
33231,
32003,
86633,
77961,
82477,
39901,
80105,
88473,
99892,
33911,
22499,
67665,
83947,
25790,
10311,
54616,
67286,
32327,
13469,
71632,
69801,
38552,
31037,
64568,
22277
};


// Sort list1 & list2 from least to greatest
sort(list1.begin(), list1.end());
sort(list2.begin(), list2.end());

/* Output list1 & list 2
This is a loop to output each value in list1. 
Since each value in the list is a int, I used int, and made a temp variable called num to store each value.
list1, named of the vector being printed.
cout to output to terminal.
num is the current value being processed.
<< to send data to the output, the double quotes are acting as a space so when the numbers are printed they are separated.
The loop runs for all the values in the list until it runs out of values. Each time it runs the number being processed to stored in num
*/
cout << "List 1 from least to greatest:" << endl;
cout << list1.size() << " total values" << endl; //Shows total # of values
for (int num : list1) {
    cout << num << ", ";
}

cout << endl;
cout << endl;

cout << "List 2 from least to greatest:" << endl;
cout << list2.size() << " total values" << endl; //Shows total # of values
for (int num : list2) {
    cout << num << ", ";
}

cout << endl;

// Need to find a way to remove last comma after the final value in each list......

// Next step would probably be to get the numbers paired (smallest from each list to greatest) Since both list get sorted on lines 2044 & 2045,
// they are already least to greatest. Least starting at index [0] in both list.

// Vector to store the pairs
vector<pair<int, int>> vectorPairs;

/* Loop that pairs the values from list 1 and list 2
If i did not know the exact amount of values in the vectors i would've had to add more code.
Explination:
The loop code iterates through each index of the two vectors that house the list of numbers. It pairs their matching index numbers together. Starts at 0.
It combines them, then stores them in the vector i made on line 2079.
size_t i = 0 initializes the loop count to 0 since thats where the index starts. Each loop add 1 to i, if i is > the size of the vectors the loop stops.
Line 2090, the pairs are found, paired, and sent to the new vector, vectorPairs
*/
for (size_t i = 0; i < list1.size(); ++i) {
    vectorPairs.push_back({list1[i], list2[i]});
}

// Vector that will store my absolute differences. Formula for absolute differences is abs(x-y): abs is the function to find absolute value.
vector<int> absDifferences;

// Calculation to find absolute differences for each pair

for (auto& p : vectorPairs) { // Loop to cover each pair
    int diff = abs(p.first - p.second); // Gives the values
    absDifferences.push_back(diff); // Stores the abs differences 
}

cout << endl;
cout << "List of absolute differences: " << endl;

// Loops that prints each absolute difference from the pairs
for (int diff : absDifferences) {
    cout << diff << endl;
}

cout << endl;

auto result = reduce(absDifferences.begin(), absDifferences.end());
cout << "Total distance between all pairs is:  " << result;



}