#include <iostream>
//#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

//--------memo---------------------------------------
/*
実装予定
・本日
ステータス
・未定
レベル機能
バトル
拠点機能
*/

//--------typedef---------------------------------------------
typedef struct position{
  int x;
  int y;
} Position;

typedef struct item_basis{
  string name;
  vector<string> classes;
} Item_Basis;

typedef struct item{
  int number;
  int quantity;
  vector<int> option_int;
} Item;

typedef struct material{
  string name;
  int quantity;
  vector<int> option_int;
} Material;

typedef struct item_recipe{
  Item item;
  vector<Material> items_list;
} Item_Recipe;

typedef struct status{
  int hp;
  int str;
  int def;
  int physical_level;
  int physical_exp;
  int alchemistic_level;
  int alchemistic_exp;
} Status;

typedef struct status_each_physical_level{
  int physical_level;
  int hp;
  int str;
  int def;
  int exp_next;
} Status_Each_Physical_Level;

typedef struct status_each_alchemistic_level{
  int alchemistic_level;
  int exp_next;
} Status_Each_Alchemistic_Level;

typedef struct abnormal_status{
  int number;
  vector<int> option_int;
} Abnormal_Status;

typedef struct status_basis{
  string name;
  vector<string> classes;
} Status_Basis;

typedef struct mass{
  string status;
  Item item;
} Mass;

typedef struct mob_basis{
  string name;
  Status status;
  vector<Item> rare_1;
  vector<Item> rare_2;
  vector<Item> rare_3;
} Mob_Basis;

typedef struct player{
  string classification;
  int turn_player_number;
  Position position;
  string name;
  int corner;
  Status status;
  vector<Item> items;
  vector<Abnormal_Status> abnormal_status;
  int last_attacked_player;
  vector<int> option_int;
} Player;

typedef struct world{
  vector<vector<Mass>> field;
  vector<Player> player_list;
  int turn_player_number;
} World;
//--------encyclopedia-----------------------------------------
/*
static vector<Item_Basis> encyclopedia = {
  {"Plant", {"Material", "Plant"}},
  {"Ore", {"Material", "Ore", "Gunpowder"}},
  {"Water", {"Material", "Water"}},
  {"Fruit", {"Material", "Fruit"}},
  {"Fish", {"Material", "Fish"}},
  {"Animal", {"Material", "Animal"}},
  //mix_item
  {"Medicine", {"Material", "Battle", "Turn Start", "Turn", "Instant"}},
  {"Uni Bomb", {"Material", "Battle", "Instant"}},
  {"Bomb", {"Material", "Battle", "Instant"}},
  {"Paper", {"Material", "Paper", "Fuel"}},
  {"Red Neutralizer", {"Material", "Neutralizer"}},
  //dice_item(test)
  {"Normal Dice + a", {"Dice", "Turn Start"}}
};
*/
static vector<Status_Each_Physical_Level> encyclopedia_phy_lv = {
  {0, 999, 999, 999, 999},
  {1, 10, 30, 0, 2},
  {2, 11, 40, 0, 4},
  {3, 12, 50, 0, 8},
  {4, 13, 60, 0, 12},
  {5, 14, 70, 0, 10000},
};
static vector<Status_Each_Alchemistic_Level> encyclopedia_alc_lv = {
  {0, 999},
  {1, 2},
  {2, 4},
  {3, 8},
  {4, 12},
  {5, 10000}
};
///*
static vector<Item_Basis> encyclopedia = {
  {"魔法の草", {"植物類", "薬の材料"}},
  {"コバルト草", {"植物類","水"}},
  {"妖精の毒草", {"植物類","毒の材料"}},
  {"ミスティックハーブ", {"植物類","神秘の力","薬の材料"}},
  {"夕焼け草", {"植物類","燃料"}},
  {"五日ヅル", {"植物類","神秘の力"}},
  {"峰綿花", {"植物類","糸素材","燃料"}},
  {"苔むした流木", {"木材","植物類"}},
  {"キーファ", {"木材","植物類"}},
  {"アルタル", {"植物類","薬の材料"}},
  {"紅草", {"植物類","薬の材料"}},
  {"シロツメクサ", {"植物類","薬の材料"}},
  {"常世の仙花", {"植物類","エリキシル"}},
  {"ドンケルハイト", {"植物類","薬の材料","エリキシル"}},
  {"ドンケルシュテルン", {"植物類","毒の材料","神秘の力"}},
  {"アイゼン鉱", {"鉱石"}},
  {"ライデン鉱", {"鉱石"}},
  {"クプルフ鉱", {"鉱石"}},
  {"カーエン石", {"鉱石","火薬"}},
  {"ハクレイ石", {"鉱石","宝石"}},
  {"ソウルストン", {"鉱石","金属"}},
  {"黒の燃球", {"鉱石","毒の材料","燃料"}},
  {"妖精の土だんご", {"粘土","薬の材料"}},
  {"湖底の土", {"粘土"}},
  {"海底の土", {"粘土"}},
  {"古い石板", {"鉱石","粘土","神秘の力"}},
  {"砕けた石材", {"鉱石","粘土"}},
  {"古代の石柱", {"鉱石","植物類"}},
  {"くすぶる鍛石", {"鉱石","粘土","金属"}},
  {"ファーデンライト", {"鉱石","糸素材"}},
  {"夜水晶", {"鉱石","宝石"}},
  {"輝く原石", {"鉱石","宝石"}},
  {"銀霊結晶", {"鉱石","神秘の力"}},
  {"精霊結晶", {"鉱石","宝石","エリキシル","神秘の力"}},
  {"魔鳥の羽", {"動物素材","糸素材"}},
  {"丈夫な骨", {"動物素材","薬の材料"}},
  {"島魚のヒレ", {"動物素材","食材","薬の材料"}},
  {"ケモノの毛皮", {"動物素材","糸素材"}},
  {"アカツキの毛皮", {"動物素材","糸素材"}},
  {"粘銀の糸", {"糸素材"}},
  {"粘金の鋼糸", {"糸素材"}},
  {"竜のウロコ", {"動物素材","薬の材料","エリキシル"}},
  {"井戸水", {"水"}},
  {"おいしい水", {"水"}},
  {"キルヘンミルク", {"食材","水"}},
  {"夜光水", {"水","神秘の力"}},
  {"ニトロ水", {"火薬","水","毒の材料"}},
  {"妖しい液体", {"水","毒の材料"}},
  {"プ二の体液", {"水","薬の材料"}},
  {"虹プ二の体液", {"水","神秘の力","薬の材料"}},
  {"竜の血晶", {"水","エリキシル","毒の材料"}},
  {"聖水", {"水","神秘の力"}},
  {"プニプニ玉", {"食材","神秘の力"}},
  {"黄金のプニプニ玉", {"食材","神秘の力"}},
  {"うに", {"食材","植物類"}},
  {"赤うに", {"食材","植物類","火薬"}},
  {"ラーメル麦", {"食材","植物類"}},
  {"ヴァイツェ粉", {"食材","火薬"}},
  {"土いも", {"食材","植物類"}},
  {"銀いも", {"食材","金属"}},
  {"ハチの巣", {"食材","火薬"}},
  {"正体不明のタマゴ", {"食材","燃料","薬の材料"}},
  {"きまぐれイチゴ", {"食材","植物類"}},
  {"はじけるベリー", {"食材","植物類"}},
  {"破れた紙片", {"紙","燃料"}},
  {"自然油", {"燃料"}},
  {"ザフロア油", {"燃料"}},
  {"教会のお札", {"紙","燃料"}},
  {"高級なお札", {"紙","燃料"}},
  {"敬虔な信者用お札", {"紙","燃料","魔法の道具"}},
  {"きれいな貝殻", {"宝石","薬の材料"}},
  {"ペルレムシェル", {"宝石""薬の材料"}},
  {"蒼剛石", {"宝石","鉱石"}},
  {"星の粉", {"エリキシル","火薬"}},
  {"太陽の粉", {"エリキシル","火薬"}},
  {"水晶のかけら", {"宝石","鉱石"}},
  {"虹色の水晶片", {"宝石","鉱石","神秘の力"}},
  {"ペンデローク", {"神秘の力","宝石"}},
  {"ペンデグリュン", {"神秘の力","エリキシル"}},
  {"邪な核石", {"宝石","毒の材料"}},
  {"竜核", {"宝石","神秘の力","エリキシル"}},
  {"忘れ去られた霊樹", {"木材"}},
  {"忘れ去られた宝石", {"宝石"}},
  {"忘れ去られた鉱物", {"鉱石"}},
  {"忘れ去られた部品", {"金属"}},
  {"出来損ないの欠片", {"エリキシル"}},
  {"焦げた欠片", {"エリキシル"}},
  {"臭う欠片", {"エリキシル"}},
  {"綺麗な欠片", {"エリキシル"}},
  {"失敗作の灰", {"エリキシル","魔法の道具"}},
  {"朧草の花弁", {"重要"}},
  {"久遠の竜鱗", {"重要"}},
  {"魔力を秘めたページ", {"紙","燃料","魔法の道具"}},
  {"破れた魔道書", {"魔法の道具","燃料","紙"}},
  {"未知なる知の欠片", {"紙","燃料","神秘の力"}},
  {"封じられた知の欠片", {"紙","燃料","神秘の力"}},
  {"うに袋", {"爆弾"}},
  {"フラム", {"爆弾"}},
  {"レヘルン", {"爆弾"}},
  {"ドナーストーン", {"爆弾"}},
  {"クラフト", {"爆弾"}},
  {"オリフラム", {"爆弾"}},
  {"シュタルレヘルン", {"爆弾"}},
  {"ドナークリスタル", {"爆弾"}},
  {"プニプニ弾", {"爆弾"}},
  {"神の落し物", {"爆弾","魔法の道具"}},
  {"原初の種火", {"爆弾","魔法の道具"}},
  {"魔法使いの笛", {"魔法の道具"}},
  {"天界の大掃除", {"爆弾","魔法の道具"}},
  {"終末の種火", {"爆弾","魔法の道具"}},
  {"死霊使いの笛", {"魔法の道具"}},
  {"山師の薬", {"薬品"}},
  {"リフュールボトル", {"薬品"}},
  {"そよ風のアロマ", {"薬品"}},
  {"生命の蜜", {"薬品","神秘の力"}},
  {"神秘の霊薬", {"薬品","エリキシル"}},
  {"素朴な焼き菓子", {"食品","お菓子"}},
  {"ソティー", {"食品","お菓子"}},
  {"プ二ゼリー", {"食品","お菓子","神秘の力"}},
  {"ソフィナンシェ", {"食品","お菓子"}},
  {"ピロソティー", {"食品","神秘の力"}},
  {"錬金ドロップ", {"食品","お菓子","宝石"}},
  {"プレーンワッフル", {"食品"}},
  {"ベーグルサンド", {"食品"}},
  {"最高級ホットミルク", {"食品"}},
  {"ハニーシロップ", {"薬品"}},
  {"天使のささやき", {"魔法の道具"}},
  {"万能厄除け香", {"薬品"}},
  {"不幸の瓶詰め", {"薬品"}},
  {"精霊織りの帳", {"布"}},
  {"火竜の気付け薬", {"薬品"}},
  {"万物の写本", {"魔法の道具","紙"}},
  {"小悪魔のいたずら", {"魔法の道具"}},
  {"英雄降ろしの丸薬", {"薬品"}},
  {"封じの白本", {"魔法の道具","紙"}},
  {"万能促進剤", {"薬品"}},
  {"妖精の道標", {"魔法の道具"}},
  {"生きてる荷車", {"魔法の道具","木材"}},
  {"クリアドロップ", {"魔法の道具"}},
  {"マナフェザー", {"魔法の道具","動物素材"}},
  {"旅人の靴", {"布"}},
  {"特製バックパック", {"布"}},
  {"緊急退避バッグ", {"魔法の道具"}},
  {"摘み取り軍手", {"布"}},
  {"勝者のお守り", {"魔法の道具"}},
  {"鍛錬のお守り", {"魔法の道具"}},
  {"魔除けの護符", {"魔法の道具","紙"}},
  {"ハートペンダント", {"金属"}},
  {"中和剤・赤", {"中和剤"}},
  {"中和剤・青", {"中和剤"}},
  {"中和剤・緑", {"中和剤"}},
  {"中和剤・黄", {"中和剤"}},
  {"ピュアウォーター", {"水"}},
  {"精霊の涙", {"水","神秘の力"}},
  {"アプコール", {"食材","薬の材料"}},
  {"ラーメル麦粉", {"食材","火薬"}},
  {"ハチミツ", {"食材"}},
  {"天然酵母", {"食材","火薬","毒の材料"}},
  {"万薬のもと", {"薬の材料","毒の材料"}},
  {"ゼッテル", {"紙","燃料"}},
  {"リフレッシュオイル", {"燃料","水"}},
  {"炎帝の粉", {"火薬"}},
  {"ブリッツライト", {"金属"}},
  {"ガイストアイゼン", {"金属","神秘の力"}},
  {"錬金粘土", {"粘土","エリキシル"}},
  {"束ねた金糸", {"糸素材","金属"}},
  {"スプルース", {"木材"}},
  {"インゴット", {"武器素材","金属"}},
  {"シュタルメタル", {"武器素材","金属"}},
  {"シルヴァリア", {"武器素材","金属"}},
  {"ルビリウム", {"武器素材","金属"}},
  {"ゴルトアイゼン", {"武器素材","金属"}},
  {"ハルモニウム", {"武器素材","金属"}},
  {"クロース", {"防具素材","布"}},
  {"モフコット", {"防具素材","布"}},
  {"アダールクロス", {"防具素材","布"}},
  {"フリューゲル", {"防具素材","布"}},
  {"フェアハイト", {"防具素材","布"}},
  {"ヴェルベティス", {"防具素材","布"}},
  {"雪花結晶", {"金属","宝石"}},
  {"ノーブルサファイア", {"宝石"}},
  {"夕闇の雫", {"毒の材料","水","燃料","鉱石"}},
  {"先見の水晶玉", {"宝石"}},
  {"幽世の羅針盤", {"重要"}},
  {"深紅の石", {"動物素材","火薬","エリキシル","中和剤"}},
  {"賢者の石", {"金属","薬の材料","エリキシル","神秘の力"}},
  {"日輪の雫", {"神秘の力","燃料","薬の材料","中和剤"}},
  {"ミネラルエキス", {"薬の材料","水","金属"}},
  {"緑を育む活性土", {"粘土"}},
  {"精密な部品", {"金属"}},
  {"おばあちゃんの錬金釜", {"重要"}},
  {"練習用の錬金釜", {"重要"}},
  {"同調の錬金釜", {"重要"}},
  {"達人の錬金釜", {"重要"}},
  {"妖精の錬金釜", {"重要"}},
  {"古代の錬金釜", {"重要"}},
  {"メルクリウスの瞳", {"魔法の道具"}},
  {"魂結いの石", {"重要"}},
  {"魂盟の針", {"重要"}},
  {"真理の鍵", {"重要"}},
  {"ヘクセ・アウリス", {"金属","魔法の道具"}},
  {"人形師の糸", {"糸素材"}},
  {"試作型栄養剤", {"重要"}},
  {"デート券", {"重要"}},
  {"うるおい草", {"重要"}}
  /*
  {, {}},
  {, {}},
  {, {}},
  {, {}},
  {, {}},
  {, {}},
  {, {}},
  */
};
//*/
int Item_Number(string name){
  int counter = 0;
  for(auto itr = encyclopedia.begin(); itr != encyclopedia.end(); itr++){
    if(name == itr->name){
      return counter;
    }
    counter++;
  }
  return -1;
  cout << "[Error!]:Access to non installed item" << endl;
}
Item Create_Item(string name, int quantity, vector<int> option_int){
  Item item;
  item.number = Item_Number(name);
  item.quantity = quantity;
  item.option_int = option_int;
  return item;
}
Abnormal_Status Create_Abnormal_Status(string name, vector<int> option_int){
  Abnormal_Status status;
  status.number = Item_Number(name);
  status.option_int = option_int;
  return status;
}
Material Create_Material(string name, int quantity, vector<int> option_int){
  Material material;
  material.name = name;
  material.quantity = quantity;
  material.option_int = option_int;
  return material;
}

/*
static vector<Mob_Basis> encyclopedia_mob = {
  {"Rabbit", {5, 1, 0, 0, 2, 0, 0}, {Create_Item("Animal", 1, {1})}},
  {"Puni", {4, 2, 0, 0, 2, 0, 1}, {Create_Item("Animal", 1, {2})}},
  {"Dragon", {100, 30, 0, 0, 100, 0, 100}, {Create_Item("Animal", 5, {3})}}
};
*/
static vector<Mob_Basis> encyclopedia_mob = {
  {"青プ二", {18, 5, 6, 1, 1, 0, 0}, {Create_Item("プニプニ玉", 1, {1})}, {Create_Item("プ二の体液", 1, {1})}, {Create_Item("黄金のプニプニ玉", 1, {1})}},
  {"緑プ二", {32, 13, 15, 4, 4, 0, 0}, {Create_Item("プニプニ玉", 1, {1})}, {Create_Item("プ二の体液", 1, {1})}, {Create_Item("黄金のプニプニ玉", 1, {1})}},
  {"赤プ二", {54, 21, 25, 7, 8, 0, 0}, {Create_Item("プニプニ玉", 1, {1})}, {Create_Item("プ二の体液", 1, {1})}, {Create_Item("黄金のプニプニ玉", 1, {1})}},
  {"金プ二", {72, 26, 32, 9, 12, 0, 0}, {Create_Item("プニプニ玉", 1, {1})}, {Create_Item("プ二の体液", 1, {1})}, {Create_Item("黄金のプニプニ玉", 1, {1})}},
  {"黒プ二", {208, 57, 63, 12, 30, 0, 0}, {Create_Item("プニプニ玉", 1, {1})}, {Create_Item("プ二の体液", 1, {1})}, {Create_Item("妖しい液体", 1, {1}), Create_Item("蒼剛石", 1, {1}), Create_Item("ペルレムシェル", 1, {1}), Create_Item("アカツキの毛皮", 1, {1})}},
  {"ぷにぷに？", {265, 81, 81, 15, 47, 0, 0}, {Create_Item("黄金のプニプニ玉", 1, {1})}, {Create_Item("妖しい液体", 1, {1})}, {Create_Item("ライデン鉱", 1, {1}), Create_Item("ハクレイ石", 1, {1}), Create_Item("くすぶる鍛石", 1, {1}), Create_Item("クプルフ鉱", 1, {1})}},
  {"すーぱーぷに", {950, 97, 75, 16, 105, 0, 0}, {Create_Item("黄金のプニプニ玉", 1, {1})}, {Create_Item("虹プ二の体液", 1, {1})}, {}},
  {"あどみらプ二", {2700, 165, 100, 30, 482, 0, 0}, {Create_Item("黄金のプニプニ玉", 1, {1})}, {Create_Item("虹プ二の体液", 1, {1})}, {}},
  {"マジックブック", {51, 22, 30, 7, 8, 0, 0}, {Create_Item("破れた紙片", 1, {1})}, {Create_Item("水晶のかけら", 1, {1})}, {Create_Item("アイゼン鉱", 1, {1}), Create_Item("カーエン石", 1, {1}), Create_Item("古代の石柱", 1, {1}), Create_Item("ライデン鉱", 1, {1})}},
  {"本の使い魔", {77, 30, 42, 10, 14, 0, 0}, {Create_Item("破れた紙片", 1, {1})}, {Create_Item("水晶のかけら", 1, {1})}, {Create_Item("ライデン鉱", 1, {1}), Create_Item("ハクレイ石", 1, {1}), Create_Item("くすぶる鍛石", 1, {1}), Create_Item("クプルフ鉱", 1, {1})}},
  {"いきてる魔術書", {228, 62, 72, 14, 37, 0, 0}, {Create_Item("破れた紙片", 1, {1})}, {Create_Item("夜水晶", 1, {1})}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1})}},
  {"禁断の写本", {454, 104, 77, 18, 74, 0, 0}, {Create_Item("破れた紙片", 1, {1})}, {Create_Item("虹色の水晶片", 1, {1})}, {Create_Item("ルビリウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("フェアハイト", 1, {1})}},
  {"リッチオーダー", {1392, 154, 97, 20, 185, 0, 0}, {Create_Item("虹色の水晶片", 1, {1})}, {Create_Item("敬虔な信者用お札", 1, {1})}, {Create_Item("ルビリウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("フェアハイト", 1, {1})}},
  {"万物の智霊", {1512, 109, 102, 21, 203, 0, 0}, {Create_Item("虹色の水晶片", 1, {1})}, {}, {Create_Item("竜のウロコ", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("竜の血晶", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた部品", 1, {1}), Create_Item("ハルモニウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("ヴェルベティス", 1, {1})}},
  {"ゴースト", {12, 15, 4, 4, 3, 0, 0}, {Create_Item("水晶のかけら", 1, {1})}, {Create_Item("ペンデローク", 1, {1})}, {}},
  {"スカーレディ", {21, 24, 6, 7, 6, 0, 0}, {Create_Item("水晶のかけら", 1, {1})}, {Create_Item("ペンデローク", 1, {1})}, {}},
  {"ジェントルファントム", {82, 34, 8, 10, 13, 0, 0}, {Create_Item("水晶のかけら", 1, {1})}, {Create_Item("ペンデローク", 1, {1})}, {}},
  {"ホーント", {183, 75, 15, 15, 33, 0, 0}, {Create_Item("ペンデローク", 1, {1})}, {}, {Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("聖水", 1, {1}), Create_Item("教会のお札", 1, {1}), Create_Item("高級なお札", 1, {1}), Create_Item("敬虔な信者用お札", 1, {1})}},
  {"ファニーフェイス", {1192, 152, 107, 19, 161, 0, 0}, {Create_Item("水晶のかけら", 1, {1})}, {}, {Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"漆黒の乙女", {1530, 121, 127, 22, 219, 0, 0}, {Create_Item("水晶のかけら", 1, {1})}, {}, {Create_Item("ルビリウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("フェアハイト", 1, {1})}},
  {"マンドラゴラ", {60, 14, 0, 4, 4, 0, 0}, {Create_Item("魔法の草", 1, {1})}, {}, {Create_Item("ラーメル麦", 1, {1}), Create_Item("うに", 1, {1}), Create_Item("土いも", 1, {1})}},
  {"ホワイトルート", {119, 26, 0, 8, 11, 0, 0}, {Create_Item("魔法の草", 1, {1})}, {Create_Item("コバルト草", 1, {1}), Create_Item("夕焼け草", 1, {1}), Create_Item("赤うに", 1, {1}), Create_Item("苔むした流木", 1, {1})}, {Create_Item("妖精の毒草", 1, {1}), Create_Item("五日ヅル", 1, {1}), Create_Item("峰綿花", 1, {1}), Create_Item("はじけるベリー", 1, {1})}},
  {"アルラウネ", {204, 53, 0, 12, 24, 0, 0}, {Create_Item("魔法の草", 1, {1})}, {Create_Item("妖精の毒草", 1, {1}), Create_Item("五日ヅル", 1, {1}), Create_Item("峰綿花", 1, {1}), Create_Item("はじけるベリー", 1, {1})}, {Create_Item("コバルト草", 1, {1}), Create_Item("夕焼け草", 1, {1}), Create_Item("赤うに", 1, {1}), Create_Item("苔むした流木", 1, {1})}},
  {"キンモクジュ", {573, 78, 0, 16, 65, 0, 0}, {Create_Item("魔法の草", 1, {1})}, {Create_Item("コバルト草", 1, {1}), Create_Item("夕焼け草", 1, {1}), Create_Item("赤うに", 1, {1}), Create_Item("苔むした流木", 1, {1})}, {Create_Item("ミスティックハーブ", 1, {1}), Create_Item("銀いも", 1, {1}), Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("忘れ去られた霊樹", 1, {1})}},
  {"死告花の精", {1072, 75, 0, 15, 95, 0, 0}, {Create_Item("ドンケルシュテルン", 1, {1})}, {Create_Item("妖精の毒草", 1, {1}), Create_Item("五日ヅル", 1, {1}), Create_Item("峰綿花", 1, {1}), Create_Item("はじけるベリー", 1, {1})}, {Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"ナイトシェイド", {2048, 114, 0, 21, 247, 0, 0}, {Create_Item("ドンケルシュテルン", 1, {1})}, {Create_Item("ミスティックハーブ", 1, {1}), Create_Item("銀いも", 1, {1}), Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("忘れ去られた霊樹", 1, {1})}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1})}},
  {"ガーゴイル", {55, 20, 22, 5, 6, 0, 0}, {Create_Item("アイゼン鉱", 1, {1})}, {}, {Create_Item("古い石板", 1, {1}), Create_Item("砕けた石材", 1, {1}), Create_Item("カーエン石", 1, {1})}},
  {"アポステル", {110, 33, 37, 9, 17, 0, 0}, {Create_Item("古い石板", 1, {1}), Create_Item("砕けた石材", 1, {1}), Create_Item("アイゼン鉱", 1, {1})}, {}, {Create_Item("カーエン石", 1, {1})}},
  {"ミニデーモン", {286, 68, 65, 13, 45, 0, 0}, {Create_Item("アイゼン鉱", 1, {1})}, {Create_Item("カーエン石", 1, {1}), Create_Item("古代の石柱", 1, {1})}, {Create_Item("ライデン鉱", 1, {1}), Create_Item("ハチの巣", 1, {1}), Create_Item("ケモノの毛皮", 1, {1}), Create_Item("丈夫な骨", 1, {1}), Create_Item("自然油", 1, {1})}},
  {"トリッカー", {614, 111, 93, 19, 115, 0, 0}, {Create_Item("ライデン鉱", 1, {1})}, {Create_Item("ハクレイ石", 1, {1}), Create_Item("くすぶる鍛石", 1, {1}), Create_Item("クプルフ鉱", 1, {1})}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1})}},
  {"デビルホーン", {1626, 130, 94, 20, 251, 0, 0}, {Create_Item("邪な核石", 1, {1})}, {Create_Item("クプルフ鉱", 1, {1}), Create_Item("ソウルストン", 1, {1}), Create_Item("黒の燃球", 1, {1})}, {Create_Item("忘れ去られた鉱物", 1, {1})}},
  {"封印されし魔王", {2188, 161, 121, 24, 395, 0, 0}, {Create_Item("邪な核石", 1, {1})}, {Create_Item("クプルフ鉱", 1, {1}), Create_Item("ソウルストン", 1, {1}), Create_Item("黒の燃球", 1, {1})}, {Create_Item("忘れ去られた鉱物", 1, {1}), Create_Item("ハルモニウム", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("虹プ二の体液", 1, {1}), Create_Item("敬虔な信者用お札", 1, {1}), Create_Item("ペンデグリュン", 1, {1}), Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("銀霊結晶", 1, {1}), Create_Item("忘れ去られた部品", 1, {1})}},
  {"アードラ", {50, 21, 21, 6, 8, 0, 0}, {Create_Item("魔鳥の羽", 1, {1})}, {}, {Create_Item("ハチの巣", 1, {1}), Create_Item("ケモノの毛皮", 1, {1}), Create_Item("丈夫な骨", 1, {1}), Create_Item("自然油", 1, {1})}},
  {"カイゼルピジョン", {79, 30, 30, 9, 15, 0, 0}, {Create_Item("魔鳥の羽", 1, {1})}, {Create_Item("正体不明のタマゴ", 1, {1}), Create_Item("きれいな貝殻", 1, {1}), Create_Item("粘銀の糸", 1, {1}), Create_Item("ザフロア油", 1, {1})}, {Create_Item("妖しい液体", 1, {1}), Create_Item("蒼剛石", 1, {1}), Create_Item("ペルレムシェル", 1, {1}), Create_Item("アカツキの毛皮", 1, {1})}},
  {"セイバークロウ", {234, 61, 54, 13, 41, 0, 0}, {Create_Item("魔鳥の羽", 1, {1})}, {Create_Item("妖しい液体", 1, {1}), Create_Item("蒼剛石", 1, {1}), Create_Item("ペルレムシェル", 1, {1}), Create_Item("アカツキの毛皮", 1, {1})}, {Create_Item("正体不明のタマゴ", 1, {1}), Create_Item("きれいな貝殻", 1, {1}), Create_Item("粘銀の糸", 1, {1}), Create_Item("ザフロア油", 1, {1})}},
  {"グスタフ", {438, 81, 65, 16, 76, 0, 0}, {Create_Item("魔鳥の羽", 1, {1})}, {Create_Item("正体不明のタマゴ", 1, {1}), Create_Item("きれいな貝殻", 1, {1}), Create_Item("粘銀の糸", 1, {1}), Create_Item("ザフロア油", 1, {1})}, {Create_Item("妖しい液体", 1, {1}), Create_Item("蒼剛石", 1, {1}), Create_Item("ペルレムシェル", 1, {1}), Create_Item("アカツキの毛皮", 1, {1})}},
  {"ロック", {1564, 124, 81, 20, 241, 0, 0}, {Create_Item("魔鳥の羽", 1, {1})}, {}, {Create_Item("竜のウロコ", 1, {1}), Create_Item("虹色の水晶片", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("竜の血晶", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた部品", 1, {1})}},
  {"月天の霊鳥", {1968, 88, 78, 23, 327, 0, 0}, {Create_Item("魔鳥の羽", 1, {1})}, {Create_Item("ファーデンライト", 1, {1})}, {Create_Item("星の粉", 1, {1})}},
  {"キメラビースト", {126, 33, 28, 8, 19, 0, 0}, {Create_Item("ケモノの毛皮", 1, {1})}, {Create_Item("丈夫な骨", 1, {1})}, {Create_Item("ハチの巣", 1, {1}), Create_Item("自然油", 1, {1})}},
  {"ライトニング", {216, 53, 41, 12, 41, 0, 0}, {Create_Item("ケモノの毛皮", 1, {1})}, {Create_Item("丈夫な骨", 1, {1})}, {Create_Item("妖しい液体", 1, {1}), Create_Item("蒼剛石", 1, {1}), Create_Item("ペルレムシェル", 1, {1}), Create_Item("アカツキの毛皮", 1, {1})}},
  {"ファング", {442, 98, 68, 16, 96, 0, 0}, {Create_Item("丈夫な骨", 1, {1})}, {Create_Item("アカツキの毛皮", 1, {1})}, {Create_Item("正体不明のタマゴ", 1, {1}), Create_Item("きれいな貝殻", 1, {1}), Create_Item("粘銀の糸", 1, {1}), Create_Item("ザフロア油", 1, {1})}},
  {"ツインヘッダー", {772, 129, 84, 20, 181, 0, 0}, {Create_Item("丈夫な骨", 1, {1})}, {Create_Item("アカツキの毛皮", 1, {1})}, {Create_Item("竜のウロコ", 1, {1}), Create_Item("虹色の水晶片", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("竜の血晶", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた部品", 1, {1})}},
  {"沈黙の魔獣", {400, 60, 43, 10, 49, 0, 0}, {Create_Item("アカツキの毛皮", 1, {1})}, {}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1}), Create_Item("妖しい液体", 1, {1}), Create_Item("蒼剛石", 1, {1}), Create_Item("ペルレムシェル", 1, {1})}},
  {"紅蓮の牙", {2530, 104, 76, 22, 484, 0, 0}, {Create_Item("アカツキの毛皮", 1, {1})}, {Create_Item("ルビリウム", 1, {1})}, {Create_Item("太陽の粉", 1, {1})}},
  {"島魚", {106, 33, 33, 9, 21, 0, 0}, {Create_Item("島魚のヒレ", 1, {1})}, {Create_Item("丈夫な骨", 1, {1})}, {Create_Item("湖底の土", 1, {1})}},
  {"一本角", {158, 48, 43, 12, 36, 0, 0}, {Create_Item("島魚のヒレ", 1, {1})}, {Create_Item("丈夫な骨", 1, {1})}, {Create_Item("魔法の草", 1, {1}), Create_Item("ラーメル麦", 1, {1}), Create_Item("うに", 1, {1}), Create_Item("土いも", 1, {1})}},
  {"大星魚", {351, 88, 71, 16, 85, 0, 0}, {Create_Item("島魚のヒレ", 1, {1})}, {}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1}), Create_Item("妖精の毒草", 1, {1}), Create_Item("五日ヅル", 1, {1}), Create_Item("峰綿花", 1, {1}), Create_Item("はじけるベリー", 1, {1})}},
  {"タイラントホルン", {600, 110, 84, 19, 145, 0, 0}, {Create_Item("島魚のヒレ", 1, {1})}, {}, {Create_Item("ルビリウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("妖精の毒草", 1, {1}), Create_Item("五日ヅル", 1, {1}), Create_Item("峰綿花", 1, {1}), Create_Item("はじけるベリー", 1, {1})}},
  {"イサナシウス", {1966, 163, 100, 21, 520, 0, 0}, {Create_Item("島魚のヒレ", 1, {1})}, {Create_Item("湖底の土", 1, {1})}, {Create_Item("ペルレムシェル", 1, {1})}},
  {"グランドオーシャン", {4000, 200, 131, 25, 1154, 0, 0}, {Create_Item("島魚のヒレ", 1, {1})}, {Create_Item("海底の土", 1, {1})}, {Create_Item("忘れ去られた宝石", 1, {1})}},
  {"リッチ", {158, 58, 57, 12, 37, 0, 0}, {Create_Item("ペンデローク", 1, {1})}, {}, {}},
  {"シャドウ", {198, 72, 66, 14, 51, 0, 0}, {Create_Item("ペンデローク", 1, {1})}, {}, {}},
  {"死の審問官", {384, 116, 99, 17, 100, 0, 0}, {Create_Item("ペンデローク", 1, {1})}, {}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1})}},
  {"アークリッチ", {600, 133, 111, 19, 148, 0, 0}, {Create_Item("ペンデローク", 1, {1})}, {}, {Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"魔術師タイタス", {1966, 287, 150, 24, 474, 0, 0}, {Create_Item("ミスティックハーブ", 1, {1}), Create_Item("銀いも", 1, {1})}, {Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("忘れ去られた霊樹", 1, {1})}, {Create_Item("竜のウロコ", 1, {1}), Create_Item("虹色の水晶片", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("竜の血晶", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた部品", 1, {1}), Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"ノーライフキング", {999, 116, 94, 16, 167, 0, 0}, {}, {}, {Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("聖水", 1, {1}), Create_Item("教会のお札", 1, {1}), Create_Item("高級なお札", 1, {1}), Create_Item("敬虔な信者用お札", 1, {1})}},
  {"フレアデーモン", {146, 42, 42, 10, 27, 0, 0}, {Create_Item("邪な核石", 1, {1})}, {}, {}},
  {"サンダラス", {219, 62, 54, 13, 48, 0, 0}, {Create_Item("邪な核石", 1, {1})}, {}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1})}},
  {"ヘルゲート", {433, 111, 89, 16, 133, 0, 0}, {Create_Item("邪な核石", 1, {1})}, {}, {Create_Item("インゴット", 1, {1}), Create_Item("シュタルメタル", 1, {1}), Create_Item("クロース", 1, {1}), Create_Item("モフコット", 1, {1}), Create_Item("シルヴァリア", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("アダールクロス", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"グレートデーモン", {759, 147, 111, 20, 249, 0, 0}, {Create_Item("邪な核石", 1, {1})}, {}, {Create_Item("ハルモニウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"イフリータ", {2712, 212, 121, 21, 690, 0, 0}, {}, {}, {Create_Item("ハルモニウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("竜のウロコ", 1, {1}), Create_Item("虹色の水晶片", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("竜の血晶", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた部品", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("フリューゲル", 1, {1})}},
  {"テンペスタス", {3238, 199, 150, 24, 925, 0, 0}, {}, {}, {Create_Item("竜のウロコ", 1, {1}), Create_Item("虹色の水晶片", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("竜の血晶", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた部品", 1, {1}), Create_Item("ハルモニウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フリューゲル", 1, {1}), Create_Item("フェアハイト", 1, {1})}},
  {"ドラゴネア", {1500, 185, 98, 20, 600, 0, 0}, {Create_Item("竜のウロコ", 1, {1})}, {Create_Item("竜の血晶", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("ファーデンライト", 1, {1}), Create_Item("輝く原石", 1, {1}), Create_Item("古代の石柱", 1, {1}), Create_Item("アカツキの毛皮", 1, {1}), Create_Item("夜光水", 1, {1}), Create_Item("ニトロ水", 1, {1})}, {Create_Item("竜核", 1, {1}), Create_Item("ハルモニウム", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("太陽の粉", 1, {1}), Create_Item("星の粉", 1, {1}), Create_Item("綺麗な欠片", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた鉱物", 1, {1})}},
  {"マグマシウス", {2000, 241, 134, 25, 1000, 0, 0}, {Create_Item("竜のウロコ", 1, {1})}, {Create_Item("竜の血晶", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("ファーデンライト", 1, {1}), Create_Item("輝く原石", 1, {1}), Create_Item("古代の石柱", 1, {1}), Create_Item("アカツキの毛皮", 1, {1}), Create_Item("夜光水", 1, {1}), Create_Item("ニトロ水", 1, {1})}, {Create_Item("竜核", 1, {1}), Create_Item("ハルモニウム", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("太陽の粉", 1, {1}), Create_Item("星の粉", 1, {1}), Create_Item("綺麗な欠片", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1}), Create_Item("忘れ去られた鉱物", 1, {1})}},
  {"太陽を穢す者ヤシュク", {4000, 209, 140, 25, 1700, 0, 0}, {Create_Item("竜のウロコ", 1, {1})}, {Create_Item("竜の血晶", 1, {1})}, {Create_Item("竜核", 1, {1})}},
  {"月を祓う者ドゥラク", {3000, 241, 134, 25, 1400, 0, 0}, {Create_Item("竜のウロコ", 1, {1})}, {Create_Item("竜の血晶", 1, {1})}, {Create_Item("竜核", 1, {1})}},
  {"風のエレメンタル", {1000, 103, 84, 18, 400, 0, 0}, {}, {Create_Item("ペンデグリュン", 1, {1}), Create_Item("銀霊結晶", 1, {1}), Create_Item("精霊結晶", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("アカツキの毛皮", 1, {1}), Create_Item("焦げた欠片", 1, {1}), Create_Item("虹色の水晶片", 1, {1})}, {}},
  {"氷のエレメンタル", {2000, 227, 124, 23, 900, 0, 0}, {}, {Create_Item("ペンデグリュン", 1, {1}), Create_Item("銀霊結晶", 1, {1}), Create_Item("精霊結晶", 1, {1}), Create_Item("ルビリウム", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("粘金の鋼糸", 1, {1}), Create_Item("アカツキの毛皮", 1, {1}), Create_Item("焦げた欠片", 1, {1}), Create_Item("虹色の水晶片", 1, {1})}, {Create_Item("ハルモニウム", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("忘れ去られた霊樹", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1})}},
  {"光のエレメンタル", {4444, 240, 206, 28, 2200, 0, 0}, {}, {Create_Item("ペンデグリュン", 1, {1}), Create_Item("銀霊結晶", 1, {1}), Create_Item("精霊結晶", 1, {1}), Create_Item("ハルモニウム", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("忘れ去られた霊樹", 1, {1}), Create_Item("忘れ去られた宝石", 1, {1})}, {}},
  {"魔王", {6000, 257, 198, 30, 3000, 0, 0}, {Create_Item("ルビリウム", 1, {1}), Create_Item("ファーデンライト", 1, {1}), Create_Item("ニトロ水", 1, {1}), Create_Item("夜光水", 1, {1}), Create_Item("古代の石柱", 1, {1}), Create_Item("ペンデローク", 1, {1}), Create_Item("邪な核石", 1, {1}), Create_Item("焦げた欠片", 1, {1}), Create_Item("臭う欠片", 1, {1})}, {Create_Item("ハルモニウム", 1, {1}), Create_Item("ヴェルベティス", 1, {1}), Create_Item("虹プ二の体液", 1, {1}), Create_Item("敬虔な信者用お札", 1, {1}), Create_Item("ペンデグリュン", 1, {1}), Create_Item("ドンケルシュテルン", 1, {1}), Create_Item("銀霊結晶", 1, {1}), Create_Item("忘れ去られた部品", 1, {1}), Create_Item("忘れ去られた鉱物", 1, {1})}, {}},
  {"聖獣王ティオグレン", {2000, 159, 137, 22, 800, 0, 0}, {}, {}, {}},
  {"ナザルス", {2000, 160, 79, 20, 700, 0, 0}, {Create_Item("深紅の石", 1, {1})}, {}, {}},
  {"ルアード", {3000, 169, 128, 25, 1300, 0, 0}, {Create_Item("賢者の石", 1, {1})}, {}, {Create_Item("ハルモニウム", 1, {1}), Create_Item("ゴルトアイゼン", 1, {1}), Create_Item("フェアハイト", 1, {1}), Create_Item("ヴェルベティス", 1, {1})}},
  {"聡き竜イシリアヌス", {5000, 400, 250, 30, 5000, 0, 0}, {}, {}, {}}
  //{"", {, , , , , 0, 0}, {Create_Item("", 1, {1})}},


//  {"name", {hp, str, lv, exp, 0, 0}, {Create_Item("", 1, {1})}},
};
/*
static vector<Item_Recipe> item_recipe = {
  {Create_Item("Medicine", 1, {1}), {Create_Material("Plant", 2, {}), Create_Material("Water", 1, {})}},
  {Create_Item("Uni Bomb", 1, {1}), {Create_Material("Plant", 2, {}), Create_Material("Gunpowder", 1, {}), Create_Material("Ore", 1, {})}},
  {Create_Item("Bomb", 1, {1}), {Create_Material("Ore", 2, {}), Create_Material("Gunpowder", 1, {}), Create_Material("Paper", 1, {}), Create_Material("Neutralizer", 1, {})}}
};
*/
static vector<Item_Recipe> item_recipe = {
  {Create_Item("うに袋", 1, {1}), {Create_Material("火薬", 1, {}), Create_Material("鉱石", 1, {})}},
  {Create_Item("フラム", 1, {1}), {Create_Material("カーエン石", 2, {}), Create_Material("火薬", 1, {}), Create_Material("紙", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("レヘルン", 1, {1}), {Create_Material("ハクレイ石", 2, {}), Create_Material("水", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("ドナーストーン", 1, {1}), {Create_Material("ライデン鉱", 2, {}), Create_Material("粘土", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("クラフト", 1, {1}), {Create_Material("うに袋", 1, {}), Create_Material("金属", 2, {}), Create_Material("火薬", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("オリフラム", 1, {1}), {Create_Material("フラム", 1, {}), Create_Material("炎帝の粉", 1, {}), Create_Material("火薬", 2, {}), Create_Material("中和剤", 2, {})}},
  {Create_Item("シュタルレヘルン", 1, {1}), {Create_Material("レヘルン", 1, {}), Create_Material("雪花結晶", 2, {}), Create_Material("水", 2, {}), Create_Material("中和剤", 2, {})}},
  {Create_Item("ドナークリスタル", 1, {1}), {Create_Material("ドナーストーン", 1, {}), Create_Material("ブリッツライト", 2, {}), Create_Material("宝石", 2, {}), Create_Material("金属", 2, {})}},
  {Create_Item("プニプニ弾", 1, {1}), {Create_Material("シュタルメタル", 1, {}), Create_Material("プニプニ玉", 4, {}), Create_Material("火薬", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("神の落し物", 1, {1}), {Create_Material("ノーブルサファイア", 1, {}), Create_Material("邪な核石", 3, {}), Create_Material("爆弾", 1, {}), Create_Material("金属", 2, {})}},
  {Create_Item("原初の種火", 1, {1}), {Create_Material("深紅の石", 1, {}), Create_Material("星の粉", 3, {}), Create_Material("爆弾", 1, {}), Create_Material("神秘の力", 2, {})}},
  {Create_Item("魔法使いの笛", 1, {1}), {Create_Material("スプルース", 2, {}), Create_Material("天使のささやき", 1, {}), Create_Material("動物素材", 2, {}), Create_Material("糸素材", 2, {})}},
  {Create_Item("天界の大掃除", 1, {1}), {Create_Material("ノーブルサファイア", 1, {}), Create_Material("竜核", 1, {}), Create_Material("爆弾", 2, {}), Create_Material("金属", 2, {})}},
  {Create_Item("終末の種火", 1, {1}), {Create_Material("深紅の石", 1, {}), Create_Material("太陽の粉", 2, {}), Create_Material("爆弾", 2, {}), Create_Material("神秘の力", 2, {})}},
  {Create_Item("死霊使いの笛", 1, {1}), {Create_Material("スプルース", 2, {}), Create_Material("小悪魔のいたずら", 1, {}), Create_Material("動物素材", 3, {}), Create_Material("糸素材", 2, {})}},
  {Create_Item("山師の薬", 1, {1}), {Create_Material("魔法の草", 2, {}), Create_Material("動物素材", 1, {}), Create_Material("水", 1, {})}},
  {Create_Item("リフュールボトル", 1, {1}), {Create_Material("コバルト草", 2, {}), Create_Material("薬の材料", 2, {}), Create_Material("水", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("そよ風のアロマ", 1, {1}), {Create_Material("リフレッシュオイル", 1, {}), Create_Material("薬の材料", 2, {}), Create_Material("紙", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("生命の蜜", 1, {1}), {Create_Material("ミスティックハーブ", 2, {}), Create_Material("エリキシル", 2, {}), Create_Material("神秘の力", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("神秘の霊薬", 1, {1}), {Create_Material("ドンケルハイト", 1, {}), Create_Material("エリキシル", 2, {}), Create_Material("水", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("素朴な焼き菓子", 1, {1}), {Create_Material("うに", 2, {}), Create_Material("水", 1, {}), Create_Material("植物類", 1, {})}},
  {Create_Item("ソティー", 1, {1}), {Create_Material("植物類", 1, {}), Create_Material("燃料", 2, {}), Create_Material("水", 1, {})}},
  {Create_Item("プ二ゼリー", 1, {1}), {Create_Material("プニプニ玉", 2, {}), Create_Material("水", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("ソフィナンシェ", 1, {1}), {Create_Material("ラーメル麦粉", 3, {}), Create_Material("天然酵母", 1, {}), Create_Material("食材", 2, {}), Create_Material("水", 1, {})}},
  {Create_Item("ピロソティー", 1, {1}), {Create_Material("ミスティックハーブ", 2, {}), Create_Material("ピュアウォーター", 1, {}), Create_Material("水", 2, {}), Create_Material("紙", 1, {})}},
  {Create_Item("錬金ドロップ", 1, {1}), {Create_Material("きまぐれイチゴ", 3, {}), Create_Material("ハチミツ", 2, {}), Create_Material("紙", 1, {})}},
  {Create_Item("プレーンワッフル", 1, {1}), {Create_Material("ラーメル麦粉", 2, {}), Create_Material("ハニーシロップ", 2, {}), Create_Material("最高級ホットミルク", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("ベーグルサンド", 1, {1}), {Create_Material("ラーメル麦粉", 2, {}), Create_Material("食材", 2, {}), Create_Material("水", 1, {}), Create_Material("紙", 1, {})}},
  {Create_Item("最高級ホットミルク", 1, {1}), {Create_Material("キルヘンミルク", 2, {}), Create_Material("燃料", 2, {}), Create_Material("薬の材料", 1, {})}},
  {Create_Item("ハニーシロップ", 1, {1}), {Create_Material("ハチミツ", 1, {}), Create_Material("薬品", 1, {}), Create_Material("水", 2, {})}},
  {Create_Item("天使のささやき", 1, {1}), {Create_Material("聖水", 2, {}), Create_Material("ペンデローク", 2, {}), Create_Material("金属", 1, {}), Create_Material("粘土", 1, {})}},
  {Create_Item("万能厄除け香", 1, {1}), {Create_Material("万薬のもと", 1, {}), Create_Material("植物類", 3, {}), Create_Material("紙", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("不幸の瓶詰め", 1, {1}), {Create_Material("妖しい液体", 1, {}), Create_Material("ペンデローク", 1, {}), Create_Material("動物素材", 2, {}), Create_Material("水", 2, {})}},
  {Create_Item("精霊織りの帳", 1, {1}), {Create_Material("粘銀の糸", 2, {}), Create_Material("布", 2, {}), Create_Material("糸素材", 1, {}), Create_Material("神秘の力", 2, {})}},
  {Create_Item("火竜の気付け薬", 1, {1}), {Create_Material("竜の血晶", 1, {}), Create_Material("火薬", 2, {}), Create_Material("水", 2, {})}},
  {Create_Item("万物の写本", 1, {1}), {Create_Material("ゼッテル", 2, {}), Create_Material("ペンデローク", 1, {}), Create_Material("糸素材", 2, {}), Create_Material("神秘の力", 2, {})}},
  {Create_Item("小悪魔のいたずら", 1, {1}), {Create_Material("妖しい液体", 1, {}), Create_Material("毒の材料", 2, {}), Create_Material("金属", 1, {}), Create_Material("神秘の力", 2, {})}},
  {Create_Item("英雄降ろしの丸薬", 1, {1}), {Create_Material("竜のウロコ", 2, {}), Create_Material("エリキシル", 2, {}), Create_Material("食材", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("封じの白本", 1, {1}), {Create_Material("紙", 3, {}), Create_Material("ペンデグリュン", 1, {}), Create_Material("動物素材", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("万能促進剤", 1, {1}), {Create_Material("植物類", 3, {}), Create_Material("薬の材料", 1, {}), Create_Material("水", 2, {})}},
  {Create_Item("妖精の道標", 1, {1}), {Create_Material("木材", 2, {}), Create_Material("金属", 1, {}), Create_Material("紙", 2, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("生きてる荷車", 1, {1}), {Create_Material("スプルース", 2, {}), Create_Material("糸素材", 1, {}), Create_Material("金属", 1, {})}},
  {Create_Item("クリアドロップ", 1, {1}), {Create_Material("錬金ドロップ", 2, {}), Create_Material("食材", 1, {}), Create_Material("水", 2, {})}},
  {Create_Item("マナフェザー", 1, {1}), {Create_Material("魔鳥の羽", 2, {}), Create_Material("魔法の道具", 2, {}), Create_Material("糸素材", 1, {})}},
  {Create_Item("旅人の靴", 1, {1}), {Create_Material("動物素材", 2, {}), Create_Material("糸素材", 2, {}), Create_Material("金属", 1, {})}},
  {Create_Item("特製バックパック", 1, {1}), {Create_Material("ケモノの毛皮", 3, {}), Create_Material("神秘の力", 2, {}), Create_Material("糸素材", 1, {})}},
  {Create_Item("緊急退避バック", 1, {1}), {Create_Material("布", 2, {}), Create_Material("糸素材", 2, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("摘み取り軍手", 1, {1}), {Create_Material("動物素材", 2, {}), Create_Material("植物類", 1, {}), Create_Material("糸素材", 1, {})}},
  {Create_Item("勝者のお守り", 1, {1}), {Create_Material("高級なお札", 1, {}), Create_Material("紙", 2, {}), Create_Material("布", 1, {})}},
  {Create_Item("鍛錬のお守り", 1, {1}), {Create_Material("高級なお札", 1, {}), Create_Material("木材", 2, {}), Create_Material("布", 1, {})}},
  {Create_Item("魔除けの護符", 1, {1}), {Create_Material("敬虔な信者用お札", 1, {}), Create_Material("聖水", 2, {}), Create_Material("布", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("ハートペンダント", 1, {1}), {Create_Material("蒼剛石", 2, {}), Create_Material("金属", 1, {}), Create_Material("宝石", 1, {})}},
  {Create_Item("中和剤・赤", 5, {1}), {Create_Material("火薬", 2, {}), Create_Material("水", 2, {})}},
  {Create_Item("中和剤・青", 5, {1}), {Create_Material("鉱石", 2, {}), Create_Material("水", 2, {})}},
  {Create_Item("中和剤・緑", 5, {1}), {Create_Material("植物類", 2, {}), Create_Material("水", 2, {})}},
  {Create_Item("中和剤・黄", 5, {1}), {Create_Material("粘土", 2, {}), Create_Material("水", 2, {})}},
  {Create_Item("ピュアウォーター", 4, {1}), {Create_Material("峰綿花", 1, {}), Create_Material("キーファ", 2, {}), Create_Material("水", 1, {}), Create_Material("鉱石", 1, {})}},
  {Create_Item("精霊の涙", 3, {1}), {Create_Material("銀霊結晶", 2, {}), Create_Material("水晶のかけら", 2, {}), Create_Material("ピュアウォーター", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("アプコール", 3, {1}), {Create_Material("きまぐれイチゴ", 2, {}), Create_Material("植物類", 1, {}), Create_Material("水", 1, {})}},
  {Create_Item("ラーメル麦粉", 4, {1}), {Create_Material("ラーメル麦", 3, {}), Create_Material("紙", 1, {}), Create_Material("鉱石", 1, {})}},
  {Create_Item("ハチミツ", 3, {1}), {Create_Material("ハチの巣", 2, {}), Create_Material("中和剤", 2, {})}},
  {Create_Item("天然酵母", 3, {1}), {Create_Material("土いも", 2, {}), Create_Material("植物類", 2, {}), Create_Material("薬の材料", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("万薬のもと", 3, {1}), {Create_Material("魔法の草", 5, {}), Create_Material("毒の材料", 1, {}), Create_Material("薬の材料", 1, {}), Create_Material("エリキシル", 1, {})}},
  {Create_Item("ゼッテル", 4, {1}), {Create_Material("植物類", 3, {}), Create_Material("水", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("リフレッシュオイル", 3, {1}), {Create_Material("自然油", 2, {}), Create_Material("植物類", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("炎帝の粉", 2, {1}), {Create_Material("カーエン石", 3, {}), Create_Material("黒の燃球", 1, {}), Create_Material("火薬", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("ブリッツライト", 3, {1}), {Create_Material("ライデン鉱", 2, {}), Create_Material("ニトロ水", 1, {}), Create_Material("鉱石", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("ガイストアイゼン", 3, {1}), {Create_Material("銀霊結晶", 1, {}), Create_Material("古代の石柱", 2, {}), Create_Material("神秘の力", 1, {}), Create_Material("鉱石", 1, {})}},
  {Create_Item("錬金粘土", 2, {1}), {Create_Material("粘土", 4, {}), Create_Material("神秘の力", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("束ねた金糸", 4, {1}), {Create_Material("粘銀の糸", 2, {}), Create_Material("金属", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("スプルース", 3, {1}), {Create_Material("キーファ", 3, {}), Create_Material("木材", 1, {}), Create_Material("布", 1, {})}},
  {Create_Item("インゴット", 2, {1}), {Create_Material("鉱石", 3, {}), Create_Material("燃料", 2, {})}},
  {Create_Item("シュタルメタル", 2, {1}), {Create_Material("ライデン鉱", 3, {}), Create_Material("アイゼン鉱", 1, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("シルヴァリア", 2, {1}), {Create_Material("クプルフ鉱", 2, {}), Create_Material("ソウルストン", 1, {}), Create_Material("鉱石", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("ルビリウム", 2, {1}), {Create_Material("くすぶる鍛石", 1, {}), Create_Material("黒の燃球", 2, {}), Create_Material("鉱石", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("ゴルトアイゼン", 2, {1}), {Create_Material("ガイストアイゼン", 1, {}), Create_Material("砕けた石材", 2, {}), Create_Material("鉱石", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("ハルモニウム", 2, {1}), {Create_Material("深紅の石", 1, {}), Create_Material("精霊結晶", 2, {}), Create_Material("鉱石", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("クロース", 2, {1}), {Create_Material("糸素材", 2, {}), Create_Material("植物類", 1, {}), Create_Material("動物素材", 1, {})}},
  {Create_Item("モフコット", 2, {1}), {Create_Material("峰綿花", 2, {}), Create_Material("植物類", 1, {}), Create_Material("糸素材", 1, {}), Create_Material("動物素材", 1, {})}},
  {Create_Item("アダールクロス", 2, {1}), {Create_Material("粘銀の糸", 2, {}), Create_Material("ケモノの毛皮", 2, {}), Create_Material("植物類", 1, {}), Create_Material("水", 1, {})}},
  {Create_Item("フリューゲル", 2, {1}), {Create_Material("ファーデンライト", 1, {}), Create_Material("糸素材", 2, {}), Create_Material("動物素材", 2, {}), Create_Material("水", 1, {})}},
  {Create_Item("フェアハイト", 2, {1}), {Create_Material("束ねた金糸", 1, {}), Create_Material("ピュアウォーター", 2, {}), Create_Material("糸素材", 2, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("ヴェルベティス", 2, {1}), {Create_Material("粘金の鋼糸", 2, {}), Create_Material("虹プ二の体液", 3, {}), Create_Material("植物類", 1, {}), Create_Material("エリキシル", 1, {})}},
  {Create_Item("雪花結晶", 2, {1}), {Create_Material("銀霊結晶", 2, {}), Create_Material("水", 2, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("ノーブルサファイア", 1, {1}), {Create_Material("蒼剛石", 1, {}), Create_Material("錬金粘土", 1, {}), Create_Material("鉱石", 2, {}), Create_Material("水", 1, {})}},
  {Create_Item("夕闇の雫", 1, {1}), {Create_Material("妖しい液体", 1, {}), Create_Material("妖精の毒草", 2, {}), Create_Material("水", 1, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("先見の水晶玉", 1, {1}), {Create_Material("ペンデローク", 1, {}), Create_Material("水晶のかけら", 5, {}), Create_Material("布", 1, {}), Create_Material("粘土", 1, {})}},
  {Create_Item("幽世の羅針盤", 1, {1}), {Create_Material("魂盟の針", 4, {}), Create_Material("スプルース", 2, {}), Create_Material("紙", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("深紅の石", 1, {1}), {Create_Material("竜の血晶", 1, {}), Create_Material("星の粉", 2, {}), Create_Material("火薬", 2, {}), Create_Material("エリキシル", 1, {})}},
  {Create_Item("賢者の石", 1, {1}), {Create_Material("深紅の石", 1, {}), Create_Material("失敗作の灰", 5, {}), Create_Material("エリキシル", 2, {}), Create_Material("宝石", 1, {})}},
  {Create_Item("日輪の雫", 1, {1}), {Create_Material("太陽の粉", 2, {}), Create_Material("鉱石", 2, {}), Create_Material("精霊の涙", 1, {})}},
  {Create_Item("ミネラルエキス", 2, {1}), {Create_Material("アプコール", 1, {}), Create_Material("鉱石", 2, {}), Create_Material("中和剤", 1, {})}},
  {Create_Item("緑を育む活性土", 1, {1}), {Create_Material("万薬のもと", 1, {}), Create_Material("木材", 2, {}), Create_Material("鉱石", 2, {})}},
  {Create_Item("精密な部品", 1, {1}), {Create_Material("シュタルメタル", 1, {}), Create_Material("鉱石", 2, {}), Create_Material("燃料", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("おばあちゃんの錬金釜", 1, {1}), {Create_Material("おばあちゃんの錬金釜", 1, {}), Create_Material("鉱石", 2, {}), Create_Material("粘土", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("練習用の錬金釜", 1, {1}), {Create_Material("練習用の錬金釜", 1, {}), Create_Material("鉱石", 1, {}), Create_Material("粘土", 2, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("同調の錬金釜", 1, {1}), {Create_Material("同調の錬金釜", 1, {}), Create_Material("金属", 1, {}), Create_Material("植物類", 2, {}), Create_Material("粘土", 1, {})}},
  {Create_Item("達人の錬金釜", 1, {1}), {Create_Material("達人の錬金釜", 1, {}), Create_Material("金属", 2, {}), Create_Material("粘土", 1, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("妖精の錬金釜", 1, {1}), {Create_Material("妖精の錬金釜", 1, {}), Create_Material("錬金粘土", 2, {}), Create_Material("金属", 1, {}), Create_Material("魔法の道具", 1, {})}},
  {Create_Item("古代の錬金釜", 1, {1}), {Create_Material("古代の錬金釜", 1, {}), Create_Material("錬金粘土", 2, {}), Create_Material("金属", 1, {}), Create_Material("魔法の道具", 1, {})}},
  {Create_Item("メルクリウスの瞳", 1, {1}), {Create_Material("水晶のかけら", 1, {}), Create_Material("ペンデローク", 1, {}), Create_Material("金属", 1, {}), Create_Material("糸素材", 1, {})}},
  {Create_Item("魂盟の針", 1, {1}), {Create_Material("魂結いの石", 1, {}), Create_Material("水", 2, {}), Create_Material("粘土", 1, {})}},
  {Create_Item("真理の鍵", 1, {1}), {Create_Material("日輪の雫", 1, {}), Create_Material("朧草の花弁", 1, {}), Create_Material("久遠の竜鱗", 1, {})}},
  {Create_Item("ヘクセ・アウリス", 1, {1}), {Create_Material("シルヴァリア", 2, {}), Create_Material("ソウルストン", 2, {}), Create_Material("宝石", 2, {}), Create_Material("神秘の力", 1, {})}},
  {Create_Item("人形師の糸", 1, {1}), {Create_Material("粘銀の糸", 2, {}), Create_Material("糸素材", 2, {}), Create_Material("燃料", 1, {})}},
  {Create_Item("試作型栄養剤", 1, {1}), {Create_Material("うるおい草", 1, {}), Create_Material("エリキシル", 1, {}), Create_Material("薬の材料", 1, {}), Create_Material("水", 1, {})}}
  /*
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  {Create_Item("", , {}), {Create_Material("", , {})}, Create_Material("", , {}),},
  */
  /*
  Create_Material("", , {}),
  */
};
static random_device rnd;
static Player NULL_player;

int Mob_Number(string name){
  int counter = 0;
  for(auto itr = encyclopedia_mob.begin(); itr != encyclopedia_mob.end(); itr++){
    if(name == itr->name){
      return counter;
    }
    counter++;
  }
  return -1;
  cout << "[Error!]:Access to non installed item" << endl;
}
Player Create_Mob(string name, Position position){
  int mob_number = Mob_Number(name);
  Player mob;
  mob.classification = "Mob";
  mob.position = position;
  mob.name = name;
  mob.corner = 4;
  mob.status = encyclopedia_mob[mob_number].status;
  mob.last_attacked_player = -1;
  mob.option_int = {mob_number};
  return mob;
}

//--------basic-------------------------------------------------
int MAX(int a, int b){
  if(a < b) return b;
  else return a;
}
int MIN(int a, int b){
  if(a < b) return a;
  else return b;
}
int Random(int a){
  /*
  int max_value = random_device::max();
  int pool = max_value - max_value % (a + 1);
  int result;
  while(1){
    result = rnd();
    if(result < pool) break;
  }
  */
  return rnd() % (a + 1);
}
int Time_Random(){
  srand(time(NULL));
  return rand();
}
int input_int(int upper){
  int a;
  while(1){
    cin >> a;
    if(!cin.fail()){
      if(a <= upper && a > 0){
        break;
      }
    }
    cout << "Error!" << endl;
    cin.clear();
    cin.ignore(1024, '\n');
  }
  for(int i = 0; i < (a * Time_Random()) % 10000; i++){
    int trash = rnd();
  }
  cout << "////////////////////////////////////////////////////////////////////////////" << endl;
  return a;
}
int input_int_zero(int upper){
  int a;
  while(1){
    cin >> a;
    if(!cin.fail()){
      if(a <= upper && a >= 0){
        break;
      }
    }
    cout << "Error!" << endl;
    cin.clear();
    cin.ignore(1024, '\n');
  }
  for(int i = 0; i < (a * Time_Random()) % 10000; i++){
    int trash = rnd();
  }
  cout << "////////////////////////////////////////////////////////////////////////////" << endl;
  return a;
}
int Sum_Vector(vector<int> v){
  int counter = 0;
  for(auto itr = v.begin(); itr != v.end(); itr++){
    counter += *itr;
  }
  return counter;
}
bool Random_bool(int numerator, int denominator){
  int flag = Random(denominator - 1);
  if(flag < numerator) return 1;
  else return 0;
}
//--------boolean-----------------------------------------------
bool isString(vector<string> datas, string name){
  for(auto itr = datas.begin(); itr != datas.end(); itr++){
    if((*itr) == name) return 1;
  }
  return 0;
}
bool isGoal(World w){
for(auto itr = w.player_list.begin(); itr != w.player_list.end(); itr++){
  if(w.field[(*itr).position.x - 1][(*itr).position.y - 1].status == "goal") return 1;
}
return 0;
}
bool isPlayer(World w, Position position){
for(auto itr = w.player_list.begin(); itr != w.player_list.end(); itr++){
  if((*itr).position.x == position.x && (*itr).position.y == position.y) return 1;
}
return 0;
}
bool isMob(World w, Position position){
for(auto itr = w.player_list.begin(); itr != w.player_list.end(); itr++){
  if((*itr).position.x == position.x && (*itr).position.y == position.y && itr->classification == "Mob") return 1;
}
return 0;
}
bool isCandidates(vector<Position> vp, Position p){
  for(auto itr = vp.begin(); itr != vp.end(); itr++){
    if((*itr).x == p.x && (*itr).y == p.y) return 1;
  }
  return 0;
}
bool isMaterial(Player player, Material material){
  int counter = 0;
  for(auto itr = player.items.begin(); itr != player.items.end(); itr++){
    if(isString(encyclopedia[itr->number].classes, material.name) || encyclopedia[itr->number].name == material.name){
      counter += itr->quantity;
    }
  }
  return counter >= material.quantity;
}
bool isMix(Player player, Item_Recipe item_recipe){
  bool ismix = 1;
  for(auto itr = item_recipe.items_list.begin(); itr != item_recipe.items_list.end(); itr++){
    ismix = ismix && isMaterial(player, *itr);
    if(ismix == 0) break;
  }
  return ismix;
}

//--------view--------------------------------------------------
void viewinVector_string(vector<string> vecstr){
if(vecstr.size() > 0){
  auto itr = vecstr.begin();
  cout << "{" << *itr << "}";
  itr++;
  while(itr != vecstr.end()){
    cout << ", {" << *itr << "}";
    itr++;
  }
}
}
void viewinPosition(Position position){
cout << "(" << position.x << ", " << position.y << ")";
}
void viewinWorld(World w){
cout << "----------World Statement----------" << endl;
/////////world statement line.1...//////////////////
for(int i = w.field[0].size() - 1; i >= 0; i--){
  if(i < 9) {
      cout << " " << i + 1;
  }
  else{
    cout << i + 1;
  }
  for(int j = 0; j < w.field.size(); j++){
    if(isPlayer(w, {j + 1, i + 1})) cout << "p";
    else cout << " ";
    if(w.field[j][i].status == "null"){
      cout << " ";
    }
    else if(w.field[j][i].status == "normal"){
      cout << "n";
    }
    else if(w.field[j][i].status == "Start"){
      cout << "s";
    }
    else if(w.field[j][i].status == "goal"){
      cout << "g";
    }
    else{
      cout << "e";
    }
  }
  cout << endl;
}
//////////world statement line.final//////////
cout << "  ";
for(int i = 0; i < w.field.size(); i++){
  if(i < 9){
    cout << " " << i + 1;
  }
  else{
    cout << i + 1;
  }
}
cout << endl;
//////////world statement line.final//////////
/*
for(int i = 0; i < w.field.size(); i++){
  for(int j = 0; j < w.field[0].size(); j++){
    cout << "[Position]:(" << i << ", " << j << ") [Status]:" << w.field[i][j].status << endl;
  }
}
*/
cout << "----------player list----------" << endl;
for(int i = 0; i < w.player_list.size(); i++){
  cout << "[Player" << i + 1 << "]://" << w.player_list[i].name << "//(" << w.player_list[i].position.x << ", " << w.player_list[i].position.y << ")" << endl;
}
cout << "-------They are whole world.-------" << endl;
}
void viewinField(World w){
  viewinWorld(w);
cout << "Please the point[x, y] you want to look up in detail" << endl;
int x = input_int(w.field.size());
int y = input_int(w.field[0].size());
/*
if(x > w.field.size() || y > w.field[0].size()){
  cout << "There is no point" << endl;
}
else{
*/
  Mass mass = w.field[x - 1][y - 1];
  cout << "--------";
  viewinPosition({x, y});
  cout << "'s details... --------" << endl;
  cout << "[STATUS]:" << mass.status << endl;
/*
  cout << "[item]:[item_name]:" << mass.item.name << endl;
  cout << "       [item_quantity]:" << mass.item.quantity << endl;
  cout << "       [item_class]:";
  viewinVector_string(mass.encyclopedia[item.number].classes);
*/
  cout << endl;
//}
}
void Dice_item(vector<int> option_int){
  if(option_int[0] == 1){
    cout << "{1d6+" << option_int[1] << "}";
  }
  if(option_int[0] == 2){
    cout << "{1d" << MAX(option_int[1], option_int[2]) - MIN(option_int[1], option_int[2]) + 1 << "+" << MIN(option_int[1], option_int[2]) - 1;
  }
  if(option_int[0] == 3){
    if(option_int.size() > 1){
      cout << "{1d.random([" << option_int[1] << "]";
      for(auto itr = option_int.begin() + 2; itr != option_int.end(); itr++){
        cout << ", [" << *itr << "]";
      }
    }
    cout << ")";
  }
}
void viewinItem(Item item){
  cout << "[Item name]://" << encyclopedia[item.number].name << " [quantity]:" << item.quantity;
  if(isString(encyclopedia[item.number].classes, "Dice")){
    cout << " [Detail]:";
    Dice_item(item.option_int);
  }
  if(isString(encyclopedia[item.number].classes, "Material")){
    cout << " [Rare]:" << item.option_int[0];
  }
}
void viewinStatus(Abnormal_Status status){
  cout << "[Status name]://" << encyclopedia[status.number].name;
  if(isString(encyclopedia[status.number].classes, "Dice")) {
    cout << " [Detail]:";
    Dice_item(status.option_int);
  }
}
void viewinPlayer(Player player){
  if(player.classification == "Player"){
    cout << "--------[Player_name]://" << player.name  << "--------" << endl;
    cout << "[turn_player_number]://" << player.turn_player_number << endl;
    cout << "[Position]://";
    viewinPosition(player.position);
    cout << endl;
    cout << "[STATUS]://" << endl;
    cout << "           -[HP]-: " << player.status.hp << "/" << encyclopedia_phy_lv[player.status.physical_level].hp << endl;
    cout << "           -[STR]-: " << player.status.str << endl;
    cout << "           -[PHY]-://[LEVEL]: " << player.status.physical_level << endl;
    cout << "                     [EXP]: " << player.status.physical_exp << "/" << encyclopedia_phy_lv[player.status.physical_level].exp_next  << " (you need [" << encyclopedia_phy_lv[player.status.physical_level].exp_next - player.status.physical_exp << "] to next level)"<< endl;
    cout << "           -[ALC]-://[LEVEL]: " << player.status.alchemistic_level << endl;
    cout << "                     [EXP]: " << player.status.alchemistic_exp << "/" << encyclopedia_alc_lv[player.status.alchemistic_level].exp_next  << " (you need [" << encyclopedia_alc_lv[player.status.alchemistic_level].exp_next - player.status.alchemistic_exp << "] to next level)"<< endl;
    cout << "[Item_List]://" << endl;
    for(auto itr = player.items.begin(); itr != player.items.end(); itr++){
      cout << "   ";
      viewinItem(*itr);
      cout << endl;
    }
    cout << "[Abnormal Status]://" << endl;
    for(auto itr = player.abnormal_status.begin(); itr != player.abnormal_status.end(); itr++){
      cout << "   ";
      viewinStatus(*itr);
      cout << endl;
    }
  }
  else if(player.classification == "Mob"){
    cout << "--------[Player_name]://" << player.name  << "--------" << endl;
    cout << "[turn_player_number]://" << player.turn_player_number << endl;
    cout << "[Position]://";
    viewinPosition(player.position);
    cout << endl;
    cout << "[STATUS]://" << endl;
    cout << "           -[HP]-: " << player.status.hp << endl; //"/" << encyclopedia_phy_lv[player.status.physical_level].hp << endl;
    cout << "           -[STR]-: " << player.status.str << endl;
    cout << "           -[PHY]-://[LEVEL]: " << player.status.physical_level << endl;
    cout << "                     [EXP]: " << player.status.physical_exp << endl;//"/" << encyclopedia_phy_lv[player.status.physical_level].exp_next  << " (you need [" << encyclopedia_phy_lv[player.status.physical_level].exp_next - player.status.physical_exp << "] to next level)"<< endl;
    cout << "           -[ALC]-://[LEVEL]: " << player.status.alchemistic_level << endl;
    cout << "                     [EXP]: " << player.status.alchemistic_exp << endl;//"/" << encyclopedia_alc_lv[player.status.alchemistic_level].exp_next  << " (you need [" << encyclopedia_alc_lv[player.status.alchemistic_level].exp_next - player.status.alchemistic_exp << "] to next level)"<< endl;
    cout << "[Abnormal Status]://" << endl;
    cout << "[Mob Number]:" << player.option_int[0] << endl;
    for(auto itr = player.abnormal_status.begin(); itr != player.abnormal_status.end(); itr++){
      cout << "   ";
      viewinStatus(*itr);
      cout << endl;
    }
  }
}
void ViewInDistinationCandidates(vector<Position> vp, int x_size, int y_size){
  vector<vector<int>> v(x_size, vector<int>(y_size, 0));
  for(auto itr = vp.begin(); itr != vp.end(); itr++){
    v[(*itr).x - 1][(*itr).y - 1] = 1;
  }
  for(int i = y_size - 1; i >= 0; i--){
    if(i < 9) {
        cout << " " << i + 1;
    }
    else{
      cout << i + 1;
    }
    for(int j = 0; j < x_size; j++){
      if(v[j][i] == 1) cout << " !";
      else cout << "  ";
    }
    cout << endl;
  }
  cout << "  ";
  for(int i = 0; i < x_size; i++){
    if(i < 9){
      cout << " " << i + 1;
    }
    else{
      cout << i + 1;
    }
  }
  cout << endl;
}
void viewinStatusChange(int pre, int post){
  cout << " " << pre << " -> " << post;
  int change = post - pre;
  if(change != 0){
    cout << " (";
    if(change > 0) cout << "+";
    cout << change << ")";
  }
}

//--------Refine, Define-----------------------------------------
vector<Item> Refine_item_by_class(Player player, string class_name){
  vector<Item> v;
  for(auto itr = player.items.begin(); itr != player.items.end(); itr++){
    if(isString(encyclopedia[itr->number].classes, class_name)) v.push_back((*itr));
  }
  return v;
}
vector<Item> Define_item_by_class(Player player, string class_name){
  vector<Item> v;
  for(auto itr = player.items.begin(); itr != player.items.end(); itr++){
    if(!isString(encyclopedia[itr->number].classes, class_name)) v.push_back((*itr));
  }
  return v;
}
vector<Abnormal_Status> Refine_status_by_class(Player player, string class_name){
  vector<Abnormal_Status> v;
  for(auto itr = player.abnormal_status.begin(); itr != player.abnormal_status.end(); itr++){
    if(isString(encyclopedia[itr->number].classes, class_name)) v.push_back((*itr));
  }
  return v;
}
vector<Abnormal_Status> Define_status_by_class(Player player, string class_name){
  vector<Abnormal_Status> v;
  for(auto itr = player.abnormal_status.begin(); itr != player.abnormal_status.end(); itr++){
    if(!isString(encyclopedia[itr->number].classes, class_name)) v.push_back((*itr));
  }
  return v;
}

//--------action on field--------------------------------------------
void sqresize(vector<vector<Mass>> *v, int x, int y){
  if(!((*v).size() >= x && (*v)[0].size() >= y)){
    int a = MAX((*v).size(), x);
    int b = MAX((*v)[0].size(), y);
    vector<vector<Mass>> vv(a, vector<Mass>(b, {"null"}));
    for(int i = 0; i < (*v).size(); i++){
      for(int j = 0; j < (*v)[0].size(); j++){
        //cout << i << j << endl;
        vv[i][j] = (*v)[i][j];
      }
    }
    (*v).resize(a);
    for(int i = 0; i < a; i++){
      (*v)[0].resize(b);
    }
    *v = vv;
  }
}
void insort_status(World *w, Position position, string s){
  sqresize(&(w->field), position.x, position.y);
  w->field[position.x - 1][position.y - 1].status = s;
}
void insort_item(World *w, Position position, Item item){
  sqresize(&(w->field), position.x, position.y);
  w->field[position.x - 1][position.y - 1].item = item;
}

//--------Dice--------------------------------------------------------
int Dice_assigned(string s){
  if(s == "2"){
    int a, b;
    cin >> a >> b;
    srand(time(NULL));
    int dice = rand() % (MAX(a, b) - MIN(a, b) + 1) + MIN(a, b);
    cout << "your number is [" << dice << "]!" << endl;
    return dice;
  }
  else if(s == "3"){
    vector<int> vi;
    string str = "0";
    while(str == "0"){
      cout << "Please enter the number [x] you will enter numbers." << endl;
      int x;
      cin >> x;
      cout << "Please enter [x] numbers." << endl;
      for(int y = 0; y < x; y++){
        int z;
        cin >> z;
        vi.push_back(z);
      }
      cout << "if you continue to enter numbers, you enter [0] or you don't do enter any." << endl;
      cin >> str;
    }
    srand(time(NULL));
    if(vi.size() == 0){
      cout << "no data return 0;" << endl;
      return 0;
    }
    else{
      int dice = vi[rand() % vi.size()];
      cout << "your number is [" << dice << "]!" << endl;
      return dice;
    }
  }
  else{
    srand(time(NULL));
    int dice = rand() % 6 + 1;
    cout << "your number is [" << dice << "]!" << endl;
    return dice;
  }
}
int Dice_auto(vector<int> option_int){
  if(option_int[0] == 2){
    srand(time(NULL));
    int dice = rand() % (MAX(option_int[1], option_int[2]) - MIN(option_int[1], option_int[2]) + 1) + MIN(option_int[1], option_int[2]);
    cout << "your number is [" << dice << "]!" << endl;
    return dice;
  }
  else if(option_int[0] == 3){
    int cell_size = option_int.size() - 1;
    srand(time(NULL));
    if(cell_size == 0){
      cout << "no data return 0;" << endl;
      return 0;
    }
    else{
      int dice = option_int[rand() % cell_size + 1];
      cout << "your number is [" << dice << "]!" << endl;
      return dice;
    }
  }
  else if(option_int[0] == 1){
    srand(time(NULL));
    int dice;
    if(option_int.size() > 1){
      dice = rand() % 6 + option_int[1] + 1;
    }
    else{
      dice = rand() % 6 + 1;
    }
    cout << "your number is [" << dice << "]!" << endl;
    return dice;
  }
  return 0;
}
int Dice(){
  string s;
  cout << "Please choose number and enter that." << endl;
  cout << "1 : [normal dice]///you can get a number for 1 ~ 6." << endl;
  cout << "2 : [range dice]///you enter two number(a, b). you can get a number for [a, b] or [b, a]." << endl;
  cout << "3 : [appoint dice]///you enter some number(a[n]). you can get a number from a[n]." << endl;
  cout << "any : [normal dice]" << endl;
  cin >> s;
  return Dice_assigned(s);
}

//--------Position---------------------------------------------------
vector<Position> Refine_Position_by_class(World world, string status){
  int x_size = world.field.size();
  int y_size = world.field[0].size();
  vector<Position> candidates;
  for(int i = 0; i < x_size; i++){
    for(int j = 0; j < y_size; j++){
      if(world.field[i][j].status == status){
        candidates.push_back({i + 1, j + 1});
      }
    }
  }
  if(candidates.size() == 0){
    cout << "[Error!]:appointed position is not existed" << endl;
    return {{0, 0}};
  }
  return candidates; // test
}

//--------player move option----------------------------------------------
  //--------option---------------------------------------//
Position MoveToCorner_position_from_int(Position position, int i){
  if(i == 0){
    position.y++;
    return position;
  }
  else if(i == 1){
    if(position.y > 1) position.y--;
    return position;
  }
  else if(i == 2){
    if(position.x > 1) position.x--;
    return position;
  }
  else if(i == 3){
    position.x++;
    return position;
  }
  else return position;
}
vector<bool> Next_Corner_basic_prot(vector<vector<Mass>> v, Position position, int i/*この方向に動いた（可能領域）*/){
  vector<bool> vec;
  int x = v.size();
  int y = v[0].size();
  if(position.y == y || i == 1) vec.push_back(0);
  else vec.push_back(1);
  if(position.y == 1 || i == 0) vec.push_back(0);
  else vec.push_back(1);
  if(position.x == 1 || i == 3) vec.push_back(0);
  else vec.push_back(1);
  if(position.x == x || i == 2) vec.push_back(0);
  else vec.push_back(1);
  return vec;
}
vector<bool> Next_Corner_basic(vector<vector<Mass>> v, Position position, int i/*この方向に動いた（可能領域）*/){
  vector<bool> vec;
  int x = v.size();
  int y = v[0].size();
  Position p = MoveToCorner_position_from_int(position, i);
  if(p.y == y || i == 1) vec.push_back(0);
  else vec.push_back(1);
  if(p.y == 1 || i == 0) vec.push_back(0);
  else vec.push_back(1);
  if(p.x == 1 || i == 3) vec.push_back(0);
  else vec.push_back(1);
  if(p.x == x || i == 2) vec.push_back(0);
  else vec.push_back(1);
  return vec;
}
Player Next_Player(vector<Player> player_list, Player player){
  for(auto itr = player_list.begin(); itr != player_list.end(); itr++){
    if((*itr).name == player.name){
      itr++;
      if(itr == player_list.end()) return player_list[0];
      else return *itr;
    }
  }
  cout << "There is no player who matchs to the player" << endl;
  return player;
}
  //--------Position-------------------------------------//
void Search_Position(vector<vector<Mass>> v, vector<Position> *vecpos, Position position, vector<bool> corner, int count){
  if(count == 0) (*vecpos).push_back(position);
  else{
    for(int i = 0; i < 4; i++){
      if(corner[i] == 1){
        Position p = MoveToCorner_position_from_int(position, i);
        if(v[p.x - 1][p.y - 1].status != "null"){
          Search_Position(v, vecpos, p, Next_Corner_basic(v, position, i), count - 1);
        }
      }
    }
  }
}
void destination(World *world, vector<Position> *vec, Position start_point, int dice_number){
  Search_Position(world->field, vec, start_point, Next_Corner_basic_prot(world->field, start_point, world->player_list[world->turn_player_number].corner), dice_number);
}
int Corner_Neighboorhood(Position from, Position to){
  int dx = to.x - from.x;
  int dy = to.y - from.y;
  if(dx == 0 && dy == 1) return 0;
  if(dx == 0 && dy == -1) return 1;
  if(dx == -1 && dy == 0) return 2;
  if(dx == 1 && dy == 0) return 3;
  return 4;
}
  //--------Route----------------------------------------//
void Search_Route(World *world, vector<vector<Position>> *v, vector<Position> route, Position current_location, Position destination, vector<bool> corner, int counter){
  route.push_back(current_location);
  if(current_location.x == destination.x && current_location.y == destination.y && counter == 0) (*v).push_back(route);
  if(counter > 0){
    for(int i = 0; i < 4; i++){
      if(corner[i] == 1){
        Position p = MoveToCorner_position_from_int(current_location, i);
        if(world->field[p.x - 1][p.y - 1].status != "null"){
          Search_Route(world, v, route, p, destination, Next_Corner_basic(world->field, current_location, i), counter - 1);
        }
      }
    }
  }
}
void Route(World *world, Position start, Position destination, int dice_number){
  vector<vector<Position>> route_candidates;
  vector<Position> route;
  Search_Route(world, &route_candidates, route, start, destination, Next_Corner_basic_prot(world->field, start, world->player_list[world->turn_player_number].corner), dice_number);
  int candidates_size = route_candidates.size();
  if(candidates_size > 1){
    cout << "Please choose your route number." << endl;
    for(int i = 0; i < candidates_size; i++){
      cout << "[" << i + 1 << "]:";
      for(auto itr = route_candidates[i].begin(); itr != route_candidates[i].end(); itr++){
        cout << "(" << (*itr).x << ", " << (*itr).y << ") ";
      }
      cout << endl;
    }
    int i = input_int(candidates_size);
    route_candidates[0] = route_candidates[i - 1];
  }
  int route_size = route_candidates[0].size();
  world->player_list[world->turn_player_number].corner = Corner_Neighboorhood(route_candidates[0][route_size - 2], route_candidates[0][route_size - 1]);
}
bool isOneDistination(vector<Position> vp){
  Position p = vp[0];
  for(auto itr = vp.begin(); itr != vp.end(); itr++){
    if(p.x != (*itr).x || p.y != (*itr).y) return 0;
  }
  return 1;
}

//--------Item---------------------------------------------------------------------
void Add_Item(Player *player, Item item){
  bool flag = 0;
  for(auto itr = player->items.begin(); itr != player->items.end(); itr++){
    if(itr->number == item.number && itr->option_int == item.option_int){
      itr->quantity = itr->quantity + item.quantity;
      flag = 1;
      break;
    }
  }
  if(!flag){
    for(auto itr = player->items.begin(); itr != player->items.end(); itr++){
      if(item.number < itr->number || (item.number == itr->number && item.option_int[0] < itr->option_int[0])){
        player->items.insert(itr, item);
        flag = 1;
        break;
      }
    }
    if(!flag) player->items.push_back(item);
  }
}
void Consume_Item(Player *player, Item item){
  for(auto itr = player->items.begin(); itr != player->items.end(); itr++){
    if(itr->number == item.number && itr->option_int == item.option_int){
      itr->quantity -= item.quantity;
      if(itr->quantity == 0) player->items.erase(itr);
      else if(itr->quantity < 0) cout << "[Error!]:item quantity is below 0" << endl;
      break;
    }
  }
}
void Consume_Item_on_Mixing(Player *player, Material material){
  cout << "--------let's choose " << material.name << " --------" << endl;
  int lower;
  int counter = 0;
  vector<Item> choices;
  if(material.option_int.size() == 0){
    lower = 1;
  }
  else{
    lower = material.option_int[0];
  }
  for(auto itr = player->items.begin(); itr != player->items.end(); itr++){
    if(isString(encyclopedia[itr->number].classes, material.name)){
      if(itr->option_int[0] >= lower){
        choices.push_back(*itr);
        counter += itr->quantity;
      }
    }
  }
  if(counter < material.quantity) cout << "[Error!]:item is insufficient" << endl;
  else if(counter == material.quantity){
    for(auto itr = choices.begin(); itr != choices.end(); itr++){
      cout << "///";
      viewinItem(*itr);
      cout << endl;
      cout << "        you use this item..." << endl;
      cout << "        (Please enter the quantity you use this item) -------- " << itr->quantity << endl;
      Consume_Item(player, *itr);
    }
  }
  else if(counter > material.quantity){
    cout << "Please choose [" << material.quantity << "] items you use to mix" << endl;
    cout << "--------you use from--------" << endl;
    for(auto itr = choices.begin(); itr != choices.end(); itr++){
      cout << "----";
      viewinItem(*itr);
      cout << endl;
    }
    cout << "----------------------------" << endl;
    vector<int> choices_quantity;
    int ok = 0;
    while(ok == 0){
      vector<int> choices_quantity_candidate;
      for(auto itr = choices.begin(); itr != choices.end(); itr++){
        cout << "///";
        viewinItem(*itr);
        cout << endl;
        cout << "        you use this item..." << endl;
        cout << "        (Please enter the quantity you use this item) -------- ";
        if(Sum_Vector(choices_quantity_candidate) == material.quantity){
          cout << "0" << endl;
          choices_quantity_candidate.push_back(0);
        }
        else if(itr + 1 == choices.end()){
          int result_a = MAX(MIN(material.quantity - Sum_Vector(choices_quantity_candidate), itr->quantity), 0);
          cout << result_a << endl;
          choices_quantity_candidate.push_back(result_a);
        }
        else{
          choices_quantity_candidate.push_back(input_int_zero(MIN(material.quantity - Sum_Vector(choices_quantity_candidate), itr->quantity)));
        }
      }
      if(Sum_Vector(choices_quantity_candidate) == material.quantity){
        cout << "It's complete. OK?(Please enter [1] if you are OK or do over again, [0])" << endl;
        ok = input_int_zero(1);
        if(ok == 1) choices_quantity = choices_quantity_candidate;
      }
      else{
        cout << "[Error!]:item quantity is not correct. Please do over again" << endl;
      }
    }
    int counter2 = 0;
    for(auto itr = choices.begin(); itr != choices.end(); itr++){
      itr->quantity = choices_quantity[counter2];
      Consume_Item(player, *itr);
      counter2++;
    }
  }
}
void Use_Item(Player *player, Item item){
  for(auto itr = player->items.begin(); itr != player->items.end(); itr++){
    if(itr->number == item.number && itr->option_int == item.option_int){
      player->abnormal_status.push_back(Create_Abnormal_Status(encyclopedia[item.number].name, item.option_int));
      if(itr->quantity <= 1) player->items.erase(itr);
      else{
        itr->quantity--;
      }
      break;
    }
  }
}
void Return_item(Player *player, Abnormal_Status status){
  for(auto itr = player->abnormal_status.begin(); itr != player->abnormal_status.end(); itr++){
    if(itr->number == status.number && itr->option_int == status.option_int){
      Add_Item(player, Create_Item(encyclopedia[status.number].name, 1, status.option_int));
      player->abnormal_status.erase(itr);
      break;
    }
  }
}
void Check_before_Roll_a_Dice(Player *player){
  vector<Abnormal_Status> v = Refine_status_by_class(*player, "Dice");
  if(v.size() > 1){
    cout << "There are Competeing items![Please choose an item!]" << endl;
    int i = 1;
    for(auto itr = v.begin(); itr != v.end(); itr++){
      cout << "[" << i << "]:";
      Dice_item(itr->option_int);
      cout << endl;
      i++;
    }
    int number = input_int(i - 1);
    int k = 1;
    cout << v.size() << endl;
    for(auto itr = v.begin(); itr != v.end(); itr++){
      if(number != k){
        Return_item(player, *itr);
      }
      k++;
    }
  }
}
Item Harvest_Item(){
  /*
  vector<int> normal_item = {Item_Number("Plant"), Item_Number("Ore"), Item_Number("Water"), Item_Number("Fish"), Item_Number("Fruit")};
  vector<int> normal_quantity = {1, 1, 1, 1, 1, 2, 3};
  vector<int> normal_rare= {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3};
  Item item;
  item.number = normal_item[Random(4)];
  item.quantity = normal_quantity[Random(6)];
  item.option_int = {normal_rare[Random(10)]};
  return item;
  */
  Item item;
  int i = Random(encyclopedia.size() - 1);
  cout << "number == " << i << endl;
  item.number = i;//Random(encyclopedia.size() - 1);
  item.quantity = 1;
  item.option_int = {1};
  viewinItem(item);
  return item;
}
void Item_Mix(Player *player){
  int i = 0;
  int recipe_number = 0;
  vector<int> candidates;
  for(auto itr = item_recipe.begin(); itr != item_recipe.end(); itr++){
    if(isMix(*player, *itr)){
      cout << "[" << i + 1 << "]://" << encyclopedia[itr->item.number].name << endl;
      candidates.push_back(recipe_number);
      i++;
    }
    recipe_number++;
  }
  if(i == 0){
    cout << "You can't mix items" << endl;
  }
  else{
    Item_Recipe choice_recipe = item_recipe[candidates[input_int(i) - 1]];
    for(auto itr = choice_recipe.items_list.begin(); itr != choice_recipe.items_list.end(); itr++){
      Consume_Item_on_Mixing(player, *itr);
    }
    Add_Item(player, choice_recipe.item);
    cout << "you got " << encyclopedia[choice_recipe.item.number].name << " to mix" << endl;
  }
}
//--------player---------------------------------------------------------------
void Insert_Player(World *world, int number, Player player){
  for(auto itr = world->player_list.begin(); itr != world->player_list.end(); itr++){
    if(itr->turn_player_number >= number) itr->turn_player_number++;
    if(itr->last_attacked_player >= number) itr->last_attacked_player++;
  }
  world->player_list.insert(world->player_list.begin() + number, player);
}
void Erase_Player(World *world, int number){
  world->player_list.erase(world->player_list.begin() + number);
  if(world->turn_player_number > number) world->turn_player_number--;
  for(auto itr = world->player_list.begin(); itr != world->player_list.end(); itr++){
    if(itr->turn_player_number > number) itr->turn_player_number--;
    if(itr->last_attacked_player > number) itr->last_attacked_player--;
    else if(itr->last_attacked_player == number) itr->last_attacked_player = -1;
  }
}

//--------Status------------------------------------------------------------------
//--------Level--------------------------------------------------------------------
void check_level(Player *player){
  if(player->classification == "Player"){
    while(player->status.physical_exp >= encyclopedia_phy_lv[player->status.physical_level].exp_next){
      int pre_level = player->status.physical_level;
      int post_level = pre_level + 1;
      player->status.physical_exp -= encyclopedia_phy_lv[pre_level].exp_next;
      player->status.physical_level++;
      int pre_hp = player->status.hp;
      int increase = MAX(0, encyclopedia_phy_lv[post_level].hp -encyclopedia_phy_lv[pre_level].hp);
      player->status.hp += increase;
      player->status.str = encyclopedia_phy_lv[post_level].str;
      cout << "--------[" << player->name << "] PHYSICAL LEVEL UP to [" << post_level << "] !!--------" << endl;
      cout << "-[HP]-: " << pre_hp << "/" << encyclopedia_phy_lv[pre_level].hp << " -> " << player->status.hp << "/" << encyclopedia_phy_lv[post_level].hp << " (+" << increase << ")!" << endl;
      cout << "-[STR]- " << encyclopedia_phy_lv[pre_level].str << " -> " << encyclopedia_phy_lv[post_level].str << " (+" << encyclopedia_phy_lv[post_level].str - encyclopedia_phy_lv[pre_level].str << ")!" << endl;
      viewinPlayer(*player);
    }
    while(player->status.alchemistic_exp >= encyclopedia_alc_lv[player->status.alchemistic_level].exp_next){
      player->status.alchemistic_exp -= encyclopedia_alc_lv[player->status.alchemistic_level].exp_next;
      player->status.alchemistic_level++;
      cout << "--------[" << player->name << "] ALCHEMISTIC LEVEL UP to [" << player->status.alchemistic_level << "] !!--------" << endl;
      cout << "--- non status change---" << endl;
      viewinPlayer(*player);
    }
  }
}
void check_Alive(World *world){
  auto itr = world->player_list.begin();
  while(itr != world->player_list.end()){
    itr = world->player_list.begin();
    while(itr != world->player_list.end()){
      if(itr->status.hp <= 0){
        cout << "--------[" << itr->name << "] is [DEAD]!!--------" << endl;
        int exp_phy = itr->status.physical_exp;
        int exp_alc = itr->status.alchemistic_exp;
        if(itr->classification == "Player"){
          Position post_position = Refine_Position_by_class(*world, "Start")[0];
          cout << "[Position]:// ";
          viewinPosition(itr->position);
          cout << " -> ";
          viewinPosition(post_position);
          cout << endl;
          itr->position = post_position;
          itr->status.hp = encyclopedia_phy_lv[itr->status.physical_level].hp;
          cout << "[EXP]:// All EXPS have LOSTED..." << endl;
          itr->status.physical_exp = 0;
          itr->status.alchemistic_exp = 0;
          cout << "[ITEMS]:// ALL ITEMS have LOSTED..." << endl;
          itr->items = {};
          cout << "[Abnormal Status]:// All ABNORMAL STATUSES have CANCELLED" << endl;
          itr->abnormal_status = {};
          itr->corner = 4;
          cout << "--------[" << itr->name << "] is [REBORN]!!--------" << endl;
          viewinPlayer(*itr);
        }
        if(world->player_list[itr->last_attacked_player].classification != "NULL"){
          cout << "--------[" << world->player_list[itr->last_attacked_player].name << "] killed [" << itr->name << "]!--------" << endl;
          cout << "[" << itr->name << "]'s EXPS is DRAINED!" << endl;
          int pre_exp_phy = world->player_list[itr->last_attacked_player].status.physical_exp;
          world->player_list[itr->last_attacked_player].status.physical_exp += exp_phy;
          int post_exp_phy = world->player_list[itr->last_attacked_player].status.physical_exp;
          int pre_exp_alc = world->player_list[itr->last_attacked_player].status.alchemistic_exp;
          world->player_list[itr->last_attacked_player].status.alchemistic_exp += exp_alc;
          int post_exp_alc = world->player_list[itr->last_attacked_player].status.alchemistic_exp;
          cout << "[PHY]://[EXP]: " << pre_exp_phy <<  " -> " << post_exp_phy << "(+" << post_exp_phy - pre_exp_phy << ")" << endl;
          cout << "[ALC]://[EXP]: " << pre_exp_alc <<  " -> " << post_exp_alc << "(+" << post_exp_alc - pre_exp_alc << ")" << endl;
          viewinPlayer(world->player_list[itr->last_attacked_player]);
        }
        if(itr->classification == "Mob"){
          if(world->player_list[itr->last_attacked_player].classification == "Player"){
            vector<Item> drop_items = encyclopedia_mob[itr->option_int[0]].rare_1;
            for(auto itr2 = encyclopedia_mob[itr->option_int[0]].rare_2.begin(); itr2 != encyclopedia_mob[itr->option_int[0]].rare_2.end(); itr2++){
              if(Random_bool(80 / encyclopedia_mob[itr->option_int[0]].rare_2.size(), 100)) drop_items.push_back(*itr2);
            }
            for(auto itr2 = encyclopedia_mob[itr->option_int[0]].rare_3.begin(); itr2 != encyclopedia_mob[itr->option_int[0]].rare_3.end(); itr2++){
              if(Random_bool(20 / encyclopedia_mob[itr->option_int[0]].rare_3.size(), 100)) drop_items.push_back(*itr2);
            }
            cout << world->player_list[itr->last_attacked_player].name << " gets ..." << endl;
            for(auto itr2 = drop_items.begin(); itr2 != drop_items.end(); itr2++){
              Add_Item(&world->player_list[itr->last_attacked_player], *itr2);
              viewinItem(*itr2);
            }
            cout << endl;
          }
          cout << endl;
          Erase_Player(world, itr->turn_player_number);
          break;
        }
      }
      itr++;
    }
  }
}
void Recovery(Player *player, int recovery_amount){
  int pre_hp = player->status.hp;
  player->status.hp = MIN(player->status.hp + MAX(0, recovery_amount), encyclopedia_phy_lv[player->status.physical_level].hp);
  int post_hp = player->status.hp;
  cout << "[" << post_hp - pre_hp << "] Recover!" << endl;
  cout << "[" << player->name << "]'s HP:// ";
  viewinStatusChange(pre_hp, post_hp);
  cout << endl;

}
void Damage(Player *player, int damage){
  int pre_hp = player->status.hp;
  player->status.hp = MAX(player->status.hp - MAX(0, damage), 0);
  int post_hp = player->status.hp;
  cout << "[" << pre_hp - post_hp << "] Damage!" << endl;
  cout << "[" << player->name << "]'s HP:// ";
  viewinStatusChange(pre_hp, post_hp);
  cout << endl;
}

//--------Abnormal_Status--------------------------------------------------------
/*
void check_Abnormal_Status(World *world, int turn_player_number, string when){
  for(auto itr = player->abnormal_status.begin(); itr != player->abnormal_status; itr++){
    /////////////////////////////////////////////////////////////

    　　--型紙--
    if(encyclopedia[itr->number].name == ""){

    }

    ////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    if(isString(itr->classes, "Instant")){
      player->abnormal_status.erase(itr);
    }
  }
}
*/
//--------Attack------------------------------------------------------------------
void Attack(World *world){
  vector<Position> position_candidates;
  destination(world, &position_candidates, world->player_list[world->turn_player_number].position, 1);
  position_candidates.push_back(world->player_list[world->turn_player_number].position);
  vector<int> player_candidates;
  int i = 0;
  int j = 0;
  for(auto itr2 = world->player_list.begin(); itr2 != world->player_list.end(); itr2++){
    for(auto itr = position_candidates.begin(); itr != position_candidates.end(); itr++){
      if(itr2->position.x == itr->x && itr2->position.y == itr->y && i != world->turn_player_number){
        player_candidates.push_back(i);
        j++;
      }
    }
    i++;
  }
  if(j == 0){
    cout << "you can't attack to any player(or mob)" << endl;
  }
  else{
    cout << "Please choose player(or mob) you want to attack" << endl;
    j = 0;
    for(auto itr = player_candidates.begin(); itr != player_candidates.end(); itr++){
      cout << "[" << j + 1 << "]:////////////////////////////////////////" << endl;
      viewinPlayer(world->player_list[*itr]);
      j++;
    }
    int player_attacked = player_candidates[input_int(j) - 1];
    cout << "[0]:do nothing" << endl;
    cout << "[1]:normal attack" << endl;
    cout << "[2]:use items" << endl;
    int choice_number = input_int_zero(2);
    if(choice_number == 1){
      Damage(&world->player_list[player_attacked], world->player_list[world->turn_player_number].status.str);
      world->player_list[player_attacked].last_attacked_player = world->turn_player_number;
    }
    else if(choice_number == 2){
      cout << "this function is not installed" << endl;
    }
  }
}
void Attack_Appointed_Player(World *world, int player_attacked){
  cout << "[1]:normal attack" << endl;
  cout << "[2]:use items" << endl;
  int choice_number = input_int(2);
  if(choice_number == 1){
    Damage(&world->player_list[player_attacked], world->player_list[world->turn_player_number].status.str);
    world->player_list[player_attacked].last_attacked_player = world->turn_player_number;
  }
  else if(choice_number == 2){
    cout << "this function is not installed" << endl;
  }
}

//--------Mob-------------------------------------------------------------------
void Spone_Mob(World *world){
  /*
  vector<int> table = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2};
  vector<string> table_mob = {"Rabbit", "Puni", "Dragon"};
  Player mob = Create_Mob(table_mob[table[Random(9)]], world->player_list[world->turn_player_number].position);
  cout << "you find [" << mob.name << "]!" << endl;
  cout << "[1]:attack it" << endl;
  cout << "[2]:do nothing(& it despones)" << endl;
  int choice_number = input_int(2);
  if(choice_number == 1){
    mob.turn_player_number = world->turn_player_number + 1;
    Insert_Player(world, world->turn_player_number + 1, mob);
    Attack_Appointed_Player(world, world->turn_player_number + 1);
  }
  */
  Player mob = Create_Mob(encyclopedia_mob[Random(encyclopedia_mob.size() - 1)].name, world->player_list[world->turn_player_number].position);
  cout << "you find [" << mob.name << "]!" << endl;
  cout << "[1]:attack it" << endl;
  cout << "[2]:do nothing(& it despones)" << endl;
  int choice_number = input_int(2);
  if(choice_number == 1){
    mob.turn_player_number = world->turn_player_number + 1;
    Insert_Player(world, world->turn_player_number + 1, mob);
    Attack_Appointed_Player(world, world->turn_player_number + 1);
  }
}

//--------One turn--------------------------------------------------------------
void One_Turn_Item(World *world){
  cout << "-----------------------------------------" << endl;
  cout << "[" << world->player_list[world->turn_player_number].name << "]'s turn!" << endl;
  bool flag = 0;
  int dice_number;
  while(!flag){
    cout << "-----------------------------------------" << endl;
    cout << "Please choose your action" << endl;
    cout << "[0]:don't roll a dice" << endl;
    cout << "[1]:roll a dice" << endl;
    cout << "[2]:use items" << endl;
    cout << "[3]:look at map in detail" << endl;
    cout << "[4]:look at a player in detail" << endl;
    int choice_number = input_int_zero(4);
    if(choice_number == 0){
      flag = 1;
    }
    else if(choice_number == 1){
      Check_before_Roll_a_Dice(&world->player_list[world->turn_player_number]);
      vector<Abnormal_Status> vecsta = Refine_status_by_class(world->player_list[world->turn_player_number], "Dice");
      if(vecsta.size() == 1){
        dice_number = Dice_auto(vecsta[0].option_int);
      }
      else {
        dice_number = Dice_auto({1});
      }
      world->player_list[world->turn_player_number].abnormal_status = Define_status_by_class(world->player_list[world->turn_player_number], "Dice");
      vector<Position> vecpos;
      destination(world, &vecpos, world->player_list[world->turn_player_number].position, dice_number);
      int x = vecpos[0].x;
      int y = vecpos[0].y;
      if(!(isOneDistination(vecpos))){
        cout << "----Destination candidates are ...----" << endl;
        ViewInDistinationCandidates(vecpos, world->field.size(), world->field[0].size());
        cout << "----They are whole distination candidates----" << endl;
        cout << "Please choose your distination([x, y]) from those." << endl;
        cin >> x >> y;
        while(!(isCandidates(vecpos, {x, y}))){
          cout << "Error![It's not included in candidates]" << endl;
          cin >> x >> y;
        }
      }
      Route(world, world->player_list[world->turn_player_number].position, {x, y}, dice_number);
      world->player_list[world->turn_player_number].position = {x, y};
      flag = 1;
    }
    else if(choice_number == 2){
      int items_size = 0;
      vector<Item> turn_start_items = Refine_item_by_class(world->player_list[world->turn_player_number], "Turn Start");
      for(auto itr = turn_start_items.begin(); itr != turn_start_items.end(); itr++){
        cout << "[" << items_size + 1 << "]::";
        viewinItem(*itr);
        cout << endl;
        items_size++;
      }
      if(items_size == 0) cout << "You can't use item!" << endl;
      else{
        int choice_number_two = input_int(items_size);
        Use_Item(&world->player_list[world->turn_player_number], turn_start_items[choice_number_two - 1]);
      }
    }
    else if(choice_number == 3){
      viewinField(*world);
    }
    else if(choice_number == 4){
      cout << "Please choose number the player who you want to look at in detail has" << endl;
      for(int p_number = 0; p_number < world->player_list.size(); p_number++){
        cout << "[" << p_number + 1 <<  "]://" << world->player_list[p_number].name << endl;
        }
      int p_c_number = input_int(world->player_list.size());
      viewinPlayer(world->player_list[p_c_number - 1]);
    }
    check_Alive(world);
    check_level(&world->player_list[world->turn_player_number]);
  }
  flag = 0;
  int harvest_counter = 3;
  while(!flag){
    cout << "-----------------------------------------" << endl;
    cout << "Please choose your action" << endl;
    cout << "[1]:Harvest Item//(REST = " << harvest_counter << ")" << endl;
    cout << "[2]:Attack someone" << endl;
    cout << "[3]:search monstar" << endl;
    cout << "[4]:Mix Item" << endl;
    cout << "[5]:Use Item" << endl;
    cout << "[6]:Look at a map in detail" << endl;
    cout << "[7]:Look at a player in detail" << endl;
    cout << "[8]:Turn End" << endl;
    int choice_number = input_int(8);
    if(choice_number == 1){
      if(harvest_counter <= 0){
        cout << "you don't have the right to Harvest Item" << endl;
      }
      else{
        //harvest_counter--;
//        for(int count = 0; count < 100; count++){
          Item harvest_item = Harvest_Item();
          Add_Item(&world->player_list[world->turn_player_number], harvest_item);
          cout << "you got ";
          viewinItem(harvest_item);
          cout << "!" << endl;
//        }
      }
    }
    else if(choice_number == 2){
      Attack(world);
    }
    else if(choice_number == 3){
      Spone_Mob(world);
    }
    else if(choice_number == 4){
      Item_Mix(&world->player_list[world->turn_player_number]);
    }
    else if(choice_number == 5){
      int items_size = 0;
      vector<Item> turn_items = Refine_item_by_class(world->player_list[world->turn_player_number], "Turn");
      for(auto itr = turn_items.begin(); itr != turn_items.end(); itr++){
        cout << "[" << items_size + 1 << "]::";
        viewinItem(*itr);
        cout << endl;
        items_size++;
      }
      if(items_size == 0) cout << "You can't use items!" << endl;
      else{
        int choice_number_two = input_int(items_size);
        Use_Item(&world->player_list[world->turn_player_number], turn_items[choice_number_two - 1]);
      }
    }
    else if(choice_number == 6){
      viewinField(*world);
    }
    else if(choice_number == 7){
      cout << "Please choose number the player who you want to look at in detail has" << endl;
      for(int p_number = 0; p_number < world->player_list.size(); p_number++){
        cout << "[" << p_number + 1 <<  "]://" << world->player_list[p_number].name << endl;
      }
      int p_c_number = input_int(world->player_list.size());
      viewinPlayer(world->player_list[p_c_number - 1]);
    }
    else if(choice_number == 8){
      flag = 1;
    }
    check_Alive(world);
    check_level(&world->player_list[world->turn_player_number]);
  }
  /*
  ////////////test item/////////////
  Item dice_a = Create_Item("Normal Dice + a", 1, {1, Random(3) + 1});
  Add_Item(&world->player_list[world->turn_player_number], dice_a);
  cout << "you got ";
  Dice_item(dice_a.option_int);
  cout << " !" << endl;
  ///////////////test item//////////////
  */
  cout << "[" << world->player_list[world->turn_player_number].name << "]'s turn END." << endl;
  }
void One_Turn_Mob(World *world){
  cout << "-----------------------------------------" << endl;
  cout << "[" << world->player_list[world->turn_player_number].name << "]'s turn!" << endl;
  cout << "-----------------------------------------" << endl;
  vector<Position> position_candidates;
  destination(world, &position_candidates, world->player_list[world->turn_player_number].position, 1);
  position_candidates.push_back(world->player_list[world->turn_player_number].position);
  vector<int> player_candidates;
  int i = 0;
  int j = 0;
  for(auto itr2 = world->player_list.begin(); itr2 != world->player_list.end(); itr2++){
    for(auto itr = position_candidates.begin(); itr != position_candidates.end(); itr++){
      if(itr2->position.x == itr->x && itr2->position.y == itr->y && i != world->turn_player_number){
        player_candidates.push_back(i);
        j++;
      }
    }
    i++;
  }
  if(j == 0){
    cout << "It rests" << endl;
    Recovery(&world->player_list[world->turn_player_number], 2);
  }
  else{
    int player_attacked = -1;
    for(auto itr = player_candidates.begin(); itr != player_candidates.end(); itr++){
      if(*itr == world->player_list[world->turn_player_number].last_attacked_player){
        player_attacked = *itr;
        break;
      }
    }
    if(player_attacked == -1){
      player_attacked = player_candidates[Random(player_candidates.size() - 1)];
    }
    cout << "[" << world->player_list[world->turn_player_number].name << "] attacks [" << world->player_list[player_attacked].name << "]!" << endl;
    Damage(&world->player_list[player_attacked], world->player_list[world->turn_player_number].status.str);
    world->player_list[player_attacked].last_attacked_player = world->turn_player_number;
    check_Alive(world);
    check_level(&world->player_list[world->turn_player_number]);
  }
}
/*
void One_Turn(World *w, int turn_player_number){
  Player turn_player = w->player_list[turn_player_number];
  cout << "[" << turn_player.name << "]'s turn!" << endl;
  int dice_number = Dice();
  vector<Position> vecpos;
  destination(*w, &vecpos, turn_player.position, turn_player_number, dice_number);
  int x = vecpos[0].x;
  int y = vecpos[0].y;
  if(!(isOneDistination(vecpos))){
    cout << "----Destination candidates are ...----" << endl;
    ViewInDistinationCandidates(vecpos, w->field.size(), w->field[0].size());
    cout << "----They are whole distination candidates----" << endl;
    cout << "Please choose your distination([x, y]) from those." << endl;
    cin >> x >> y;
    while(!(isCandidates(vecpos, {x, y}))){
      cout << "Error![It's not included in candidates]" << endl;
      cin >> x >> y;
    }
  }
  Route(w, turn_player.position, {x, y}, turn_player_number, dice_number);
  w->player_list[turn_player_number].position = {x, y};
  cout << "[" << turn_player.name << "]'s turn END." << endl;
}
*/

//--------MAIN------------------------------------------------------------------
int main(){
  vector<vector<Mass>> vm(1, vector<Mass>(1, {"null"}));
  vector<Player> vp;
  World world;
  NULL_player.classification = "NULL";
  NULL_player.turn_player_number = -1;
  NULL_player.name = "NULL";
  world.field = vm;
  world.player_list = vp;
  cout << "Please enter [x, y]([status]:start)" << endl;
  int start_point_x = input_int(99);
  int start_point_y = input_int(99);
  Position p = {start_point_x, start_point_y};
  cout << "Please enter [player_number]" << endl;
  int player_number = input_int(99);
  for(int k = 0; k < player_number; k++){
    string name;
    cout << "Please enter [player" << k + 1 << " name]" << endl;
    cin >> name;
    Player player_i;
    player_i.classification = "Player";
    player_i.turn_player_number = k;
    player_i.position = p;
    player_i.name = name;
    player_i.corner = 4;
    player_i.status = {encyclopedia_phy_lv[1].hp, encyclopedia_phy_lv[1].str, 1, 0, 1, 0};
    player_i.last_attacked_player = -1;
    world.player_list.push_back(player_i);
  }
  insort_status(&world, {start_point_x, start_point_y}, "Start");
////////////addposition///////////
  while(1){
    cout << "Please enter [x, y, status] or if you finish adding masses you enter {x = 100}" << endl;
    int x = input_int(100);
    if(x == 100) break;
    int y = input_int(99);
    string s1;
    cin >> s1;
    insort_status(&world, {x, y}, s1);
  }
/////////////addposition//////////////
  viewinWorld(world);
  world.turn_player_number = 0;
  while(!(isGoal(world))){
    if(world.player_list[world.turn_player_number].classification == "Player"){
      One_Turn_Item(&world);
    }
    else if(world.player_list[world.turn_player_number].classification == "Mob"){
      One_Turn_Mob(&world);
    }
    else{
      cout << "[Error!]:non match player classification";
    }
    viewinWorld(world);
    world.turn_player_number = (world.turn_player_number + 1) % world.player_list.size();
  }
  cout << "All Completed!!" << endl;
  return 0;
}
