open Js.Typed_array;

let findGameObjectsByName = (name, engineState) =>
  engineState
  |> GameObjectEngineService.getAllGameObjects(
       SceneEngineService.getSceneGameObject(engineState),
     )
  |> Js.Array.filter(gameObject =>
       GameObjectEngineService.getGameObjectName(gameObject, engineState)
       === Some(name)
     );

let findGameObjectByName = (name, engineState) =>
  findGameObjectsByName(name, engineState) |> ArrayService.unsafeGetFirst;

let getBoxTexturedMeshGameObjects = engineState =>
  findGameObjectsByName("Mesh", engineState);

let getBoxTexturedMeshGameObject = engineState =>
  engineState |> getBoxTexturedMeshGameObjects |> ArrayService.unsafeGetFirst;

let getBoxTexturedMeshGameObjectFromAssetNode =
    (wdbNodeId, (editorState, engineState)) => {
  let wdbGameObject =
    MainEditorAssetWDBNodeTool.getWDBGameObject(wdbNodeId, editorState);

  GameObjectTool.getChild(wdbGameObject, 0, engineState);
};

let getBoxTexturedMeshGameObjectMaterialType = () => AssetMaterialDataType.LightMaterial;

let getBoxTexturedMeshGameObjectMaterialName = () => "Texture";

let getBoxTexturedMeshGameObjectTextureName = () => "texture_0";

let getBoxTexturedMeshGameObjectImageName = () => "CesiumLogoFlat.png";

let getBoxTexturedGeometryData = () => (
  Float32Array.make([|
    (-0.5),
    (-0.5),
    0.5,
    0.5,
    (-0.5),
    0.5,
    (-0.5),
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    (-0.5),
    0.5,
    0.5,
    0.5,
    (-0.5),
    0.5,
    (-0.5),
    (-0.5),
    (-0.5),
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    (-0.5),
    0.5,
    (-0.5),
    0.5,
    0.5,
    (-0.5),
    0.5,
    (-0.5),
    0.5,
    (-0.5),
    (-0.5),
    0.5,
    0.5,
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    0.5,
    (-0.5),
    0.5,
    0.5,
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    0.5,
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    (-0.5),
    0.5,
    (-0.5),
    0.5,
    (-0.5),
    (-0.5),
    0.5,
    0.5,
    (-0.5),
  |]),
  Float32Array.make([|
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    1.,
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
    0.,
    0.,
    (-1.),
  |]),
  Float32Array.make([|
    6.,
    0.,
    5.,
    0.,
    6.,
    0.9999998807907104,
    5.,
    0.9999998807907104,
    4.,
    0.,
    5.,
    0.,
    4.,
    1.,
    5.,
    1.,
    2.,
    0.,
    1.,
    0.,
    2.,
    1.,
    1.,
    1.,
    3.,
    0.,
    4.,
    0.,
    3.,
    1.,
    4.,
    1.,
    3.,
    0.,
    2.,
    0.,
    3.,
    1.,
    2.,
    1.,
    0.,
    0.,
    0.,
    0.9999998807907104,
    1.,
    0.,
    1.,
    0.9999998807907104,
  |]),
  Uint16Array.make([|
    0,
    1,
    2,
    3,
    2,
    1,
    4,
    5,
    6,
    7,
    6,
    5,
    8,
    9,
    10,
    11,
    10,
    9,
    12,
    13,
    14,
    15,
    14,
    13,
    16,
    17,
    18,
    19,
    18,
    17,
    20,
    21,
    22,
    23,
    22,
    21,
  |])
  |. Some,
  None,
);

module Truck = {
  let getTruckGameObjectName = () => "CesiumMilkTruck";

  let getTruck1GameObjectName = () => "Cesium_Milk_Truck_1";

  let getTruckGeometryData = () => {
    let map = WonderCommonlib.HashMapService.createEmpty();

    map
    |> WonderCommonlib.HashMapService.set(
         "Cesium_Milk_Truck_0",
         (
           Float32Array.make([|
             1.5424699783325195,
             1.645799994468689,
             (-1.2073999643325806),
             1.5672500133514404,
             1.7663999795913696,
             (-1.2960000038146973),
             1.5425399541854858,
             1.659019947052002,
             (-1.2018699645996094),
             1.5425399541854858,
             1.8737800121307373,
             (-1.2018699645996094),
             1.5424699783325195,
             1.8869999647140503,
             (-1.2073999643325806),
             1.542490005493164,
             1.892240047454834,
             (-1.2214800119400024),
             1.542490005493164,
             1.892240047454834,
             (-1.370519995689392),
             1.5424699783325195,
             1.8869999647140503,
             (-1.384600043296814),
             1.5425399541854858,
             1.8737800121307373,
             (-1.3901300430297852),
             1.5425399541854858,
             1.659019947052002,
             (-1.3901300430297852),
             (-1.0540000200271606),
             (-2.3183999061584473),
             0.7175999879837036,
             0.6075000166893005,
             (-2.3183999061584473),
             0.414000004529953,
             1.0440000295639038,
             1.319790005683899,
             2.5559699535369873,
             1.0745099782943726,
             1.538949966430664,
             1.6351399421691895,
             1.218269944190979,
             1.538949966430664,
             1.6351399421691895,
             1.373729944229126,
             1.5226000547409058,
             1.638659954071045,
             1.3898500204086304,
             1.5598599910736084,
             1.5812400579452515,
             1.301259994506836,
             1.5874600410461426,
             1.5812400579452515,
             1.301259994506836,
             1.5874600410461426,
             1.6050299406051636,
             1.090000033378601,
             1.5598599910736084,
             1.6050299406051636,
           |]),
           Float32Array.make([|
             0.9241639971733093,
             (-0.27296799421310425),
             0.2672260105609894,
             1.,
             (-1.456100022778628e-7),
             0.,
             0.9137849807739258,
             (-0.07294920086860657),
             0.3995949923992157,
             0.8892920017242432,
             0.05848110094666481,
             0.4535849988460541,
             0.9241639971733093,
             0.27296701073646545,
             0.2672269940376282,
             0.935841977596283,
             0.3473280072212219,
             0.0596964992582798,
             0.9197520017623901,
             0.38958001136779785,
             (-0.0477789007127285),
             0.9241639971733093,
             0.27296701073646545,
             (-0.2672269940376282),
             0.9137849807739258,
             0.07294920086860657,
             (-0.3995949923992157),
             0.8892920017242432,
             (-0.05848110094666481),
             (-0.4535849988460541),
             (-0.09013810008764267),
             (-1.),
             0.,
             0.,
             (-0.9834759831428528),
             0.,
             0.1810380071401596,
             0.8755670189857483,
             0.35023799538612366,
             0.332738995552063,
             0.6327319741249084,
             (-0.7645909786224365),
             (-0.1226859986782074),
             0.7195870280265808,
             (-0.6837360262870789),
             0.12123999744653702,
             0.,
             (-0.41054001450538635),
             0.9118430018424988,
             0.,
             (-0.9344499707221985),
             0.35609400272369385,
             0.,
             (-0.9344499707221985),
             0.35609400272369385,
             0.,
             1.,
             0.,
             0.,
             1.,
           |]),
           Float32Array.make([|
             0.8888319730758667,
             0.5682899951934814,
             0.8679770231246948,
             0.6026110053062439,
             0.8901939988136292,
             0.5718710422515869,
             0.8908870220184326,
             0.6328409910202026,
             0.889581024646759,
             0.6364309787750244,
             0.8862990140914917,
             0.6378949880599976,
             0.8504199981689453,
             0.6383479833602905,
             0.8471270203590393,
             0.6369389891624451,
             0.8457649946212769,
             0.6333580017089844,
             0.8450649976730347,
             0.5723810195922852,
             0.26473402976989746,
             0.40852299332618713,
             0.23095697164535522,
             0.45308101177215576,
             0.26473402976989746,
             0.6538209915161133,
             0.450514018535614,
             0.8863940238952637,
             0.5650860071182251,
             0.8487709760665894,
             0.5655540227890015,
             0.8424540162086487,
             0.564113974571228,
             0.8487579822540283,
             0.7149109840393066,
             0.8416500091552734,
             0.7149109840393066,
             0.8598560094833374,
             0.6718490123748779,
             0.8669649958610535,
           |]),
           Uint16Array.make([|
             0,
             1,
             2,
             2,
             1,
             3,
             3,
             1,
             4,
             4,
             1,
             5,
             5,
             1,
             6,
             6,
             1,
             7,
             7,
             1,
             8,
             8,
             1,
             9,
             9,
             1,
             10,
             10,
             1,
             11,
             1243,
             1088,
             22,
             254,
             21,
             254,
             22,
             1849,
             25,
             1850,
             24,
             1850,
             25,
             630,
             1851,
             629,
             1086,
             629,
             1851,
             482,
             483,
             1852,
             1853,
             1852,
             483,
             1854,
             1855,
             1625,
             1624,
             1625,
           |])
           |. Some,
           None,
         ),
       )
    |> WonderCommonlib.HashMapService.set(
         "Cesium_Milk_Truck_1",
         (
           Float32Array.make([|
             1.5226000547409058,
             1.638659954071045,
             1.2021499872207642,
             1.5226000547409058,
             1.6330000162124634,
             1.2170000076293945,
             1.5226000547409058,
             1.6523200273513794,
             1.1959999799728394,
             1.5226000547409058,
             1.8804800510406494,
             1.1959999799728394,
             1.5226000547409058,
             1.6330000162124634,
             1.375,
             1.5226000547409058,
             1.8941400051116943,
             1.2021499872207642,
             1.5226000547409058,
             1.638659954071045,
             1.3898500204086304,
             1.5226000547409058,
             1.8997999429702759,
             1.2170000076293945,
             1.5226000547409058,
             1.6523200273513794,
             1.3960000276565552,
             1.5226000547409058,
             1.8997999429702759,
             1.375,
             (-1.2170000076293945),
             1.5226000547409058,
             1.8804800510406494,
             (-1.1959999799728394),
             1.5226000547409058,
             1.8941400051116943,
             (-1.2021499872207642),
             0.3066819906234741,
             1.631850004196167,
             1.0549999475479126,
             0.7927179932594299,
             1.631850004196167,
             1.0549999475479126,
             0.22885000705718994,
             1.7096799612045288,
             1.0549999475479126,
             0.22885000705718994,
             2.1957199573516846,
             1.0549999475479126,
             0.8705499768257141,
             1.7096799612045288,
             1.0549999475479126,
             0.3066819906234741,
             2.273550033569336,
             1.0549999475479126,
             0.8705499768257141,
             2.1957199573516846,
             1.0549999475479126,
             0.7927179932594299,
             2.273550033569336,
           |]),
           Float32Array.make([|
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
           |]),
           Float32Array.make([||]),
           Uint16Array.make([|
             0,
             1,
             2,
             3,
             2,
             1,
             1,
             4,
             3,
             5,
             3,
             4,
             4,
             6,
             5,
             7,
             5,
             6,
             6,
             8,
             7,
             9,
             7,
             8,
             8,
             10,
             9,
             11,
             9,
             10,
             58,
             58,
             60,
             59,
             61,
             59,
             60,
             60,
             62,
             61,
             63,
             61,
             62,
             64,
             65,
             66,
             67,
             66,
             65,
             65,
             68,
             67,
             69,
             67,
             68,
             68,
             70,
             69,
             71,
             69,
           |])
           |. Some,
           None,
         ),
       )
    |> WonderCommonlib.HashMapService.set(
         "Cesium_Milk_Truck_2",
         (
           Float32Array.make([|
             1.3066400289535522,
             2.3506200313568115,
             1.090000033378601,
             1.248900055885315,
             2.3919999599456787,
             1.090000033378601,
             1.3066400289535522,
             2.3506200313568115,
             1.100000023841858,
             1.248900055885315,
             2.3919999599456787,
             1.100000023841858,
             1.465019941329956,
             1.6330000162124634,
             (-1.100000023841858),
             1.0879000425338745,
             1.6330000162124634,
             (-1.100000023841858),
             1.465019941329956,
             1.6330000162124634,
             (-1.1100000143051147),
             1.0879000425338745,
             1.6330000162124634,
             (-1.1100000143051147),
             1.1036800146102905,
             1.671090006828308,
             1.090000033378601,
             1.0822900533676147,
             1.6924799680709839,
             1.090000033378601,
             (-0.09109800308942795),
             1.4149099588394165,
             2.306770086288452,
             (-0.032999999821186066),
             1.3992700576782227,
             2.357880115509033,
             (-0.09109800308942795),
             0.2796800136566162,
             2.3092000484466553,
             1.065000057220459,
             0.8197199702262878,
             2.3092000484466553,
             1.065000057220459,
             0.2796800136566162,
             2.3092000484466553,
             1.0549999475479126,
             0.8197199702262878,
             2.3092000484466553,
             1.0549999475479126,
             0.1932000070810318,
             2.22271990776062,
             (-1.065000057220459),
             0.1932000070810318,
             1.6826800107955933,
             (-1.065000057220459),
             0.1932000070810318,
             2.22271990776062,
             (-1.0549999475479126),
             0.1932000070810318,
             1.6826800107955933,
           |]),
           Float32Array.make([|
             0.8621010184288025,
             0.5067369937896729,
             0.,
             0.40556800365448,
             0.9140650033950806,
             0.,
             0.7352259755134583,
             0.6778219938278198,
             0.,
             0.20278400182724,
             0.9792240262031555,
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.7071030139923096,
             0.7071110010147095,
             0.,
             0.7071030139923096,
             0.7071110010147095,
             0.,
             (-0.6770510077476501),
             0.21629899740219116,
             (-0.703432023525238),
             (-0.6770510077476501),
             0.21634499728679657,
             (-0.7034130096435547),
             (-0.6770560145378113),
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             0.,
           |]),
           Float32Array.make([||]),
           Uint16Array.make([|
             0,
             1,
             2,
             3,
             2,
             1,
             4,
             5,
             6,
             7,
             6,
             5,
             8,
             9,
             10,
             11,
             10,
             9,
             12,
             13,
             14,
             15,
             14,
             13,
             16,
             17,
             18,
             19,
             18,
             17,
             449,
             452,
             453,
             454,
             455,
             454,
             453,
             456,
             457,
             458,
             459,
             458,
             457,
             88,
             364,
             89,
             365,
             89,
             364,
             460,
             461,
             462,
             463,
             462,
             461,
             300,
             302,
             45,
             47,
             45,
           |])
           |. Some,
           None,
         ),
       )
    |> WonderCommonlib.HashMapService.set(
         "Wheels",
         (
           Float32Array.make([|
             (-0.04454309865832329),
             (-0.1662379950284958),
             1.0180000066757202,
             2.602089970253733e-18,
             (-6.938890181594472e-18),
             1.0180000066757202,
             (-0.08605089783668518),
             (-0.14904500544071198),
             1.0180000066757202,
             (-0.12169399857521057),
             (-0.12169399857521057),
             1.0180000066757202,
             (-0.14904500544071198),
             (-0.08605089783668518),
             1.0180000066757202,
             (-0.1662379950284958),
             (-0.04454309865832329),
             1.0180000066757202,
             (-0.17210200428962708),
             (-6.938890181594472e-18),
             1.0180000066757202,
             (-0.1662379950284958),
             0.044543299823999405,
             1.0180000066757202,
             (-0.14904500544071198),
             0.08605080097913742,
             1.0180000066757202,
             (-0.12169399857521057),
             0.12169399857521057,
             1.0180000066757202,
             (-1.0579999685287476),
             0.17392399907112122,
             0.17392399907112122,
             (-1.0579999685287476),
             (-0.17392399907112122),
             (-0.17392399907112122),
             (-1.0579999685287476),
             0.21301299333572388,
             (-0.12298300117254257),
             (-1.0579999685287476),
             0.19469000399112701,
             (-0.1124039962887764),
             (-1.0180000066757202),
             (-0.21301299333572388),
             0.12298300117254257,
             (-1.0579999685287476),
             (-0.19469000399112701),
             0.1124039962887764,
             (-1.0180000066757202),
             (-0.22480900585651398),
             (-6.938890181594472e-18),
             (-1.0180000066757202),
             0.22480900585651398,
             (-6.938890181594472e-18),
             (-1.0180000066757202),
             2.602089970253733e-18,
             (-0.4277999997138977),
             0.800000011920929,
             2.602089970253733e-18,
             (-0.4277999997138977),
           |]),
           Float32Array.make([|
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             0.,
             0.,
             1.,
             (-0.9922080039978027),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             (-0.7455800175666809),
             0.47522100806236267,
             (-0.4671989977359772),
             (-0.7843430042266846),
             0.4080820083618164,
             (-0.4671989977359772),
             0.7455800175666809,
             (-0.47522100806236267),
             (-0.46720001101493835),
             0.7843430042266846,
             (-0.4080809950828552),
             (-0.46720001101493835),
             0.,
             0.,
             (-1.),
             0.,
             0.,
             (-1.),
             (-0.043842099606990814),
             (-0.9990379810333252),
             0.,
             (-0.043842099606990814),
             (-0.9990379810333252),
           |]),
           Float32Array.make([|
             0.7119140028953552,
             0.12024599313735962,
             0.7552189826965332,
             0.15945100784301758,
             0.7032840251922607,
             0.13282698392868042,
             0.6981469988822937,
             0.1471869945526123,
             0.696977972984314,
             0.16239500045776367,
             0.6997119784355164,
             0.17739897966384888,
             0.7062950134277344,
             0.1911429762840271,
             0.7162060141563416,
             0.2027149796485901,
             0.7287200093269348,
             0.2113950252532959,
             0.7430530190467834,
             0.21653199195861816,
             0.1359959840774536,
             0.8437539935112,
             0.17873400449752808,
             0.6666010022163391,
             0.14048099517822266,
             0.7967429757118225,
             0.078823983669281,
             0.7900210022926331,
             0.0917699933052063,
             0.7140669822692871,
             0.24020302295684814,
             0.7205650210380554,
             0.22729897499084473,
             0.6913419961929321,
             0.2008960247039795,
             0.819150984287262,
             0.11831498146057129,
             0.9936569929122925,
             0.04042398929595947,
             0.9936569929122925,
           |]),
           Uint16Array.make([|
             0,
             1,
             2,
             2,
             1,
             3,
             3,
             1,
             4,
             4,
             1,
             5,
             5,
             1,
             6,
             6,
             1,
             7,
             7,
             1,
             8,
             8,
             1,
             9,
             9,
             1,
             10,
             10,
             1,
             11,
             576,
             175,
             575,
             180,
             577,
             180,
             575,
             578,
             579,
             189,
             191,
             189,
             579,
             580,
             581,
             185,
             187,
             185,
             581,
             194,
             582,
             55,
             56,
             55,
             582,
             193,
             583,
             67,
             68,
             67,
           |])
           |. Some,
           None,
         ),
       );
  };
};