#include <iostream>
//#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

//--------memo---------------------------------------
/*
�����\��
�E�{��
�X�e�[�^�X
�E����
���x���@�\
�o�g��
���_�@�\
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

typedef struct field_action{
  string name;
  vector<int> rare_1;
} Field_Action;

typedef struct field_mob{
  vector<int> normal_mobs;
  vector<int> boss_mobs;
} Field_Mob;

typedef struct field_data{
  string name;
  vector<Field_Action> field_actions;
  vector<int> normal_mobs;
  vector<int> boss_mobs;
} Field_Data;

static vector<Field_Data> encyclopedia_field = {
  {"�Â��d���̐X", {"�����΂鑐��", {Item_Number("�y����"), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number("")}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number("")}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number(""), Mob_Number("")}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {Item_Number(""), Item_Number(""), Item_Number("")}}, {}, {}},
  {"", {"", {}}, {}, {}},
  {"", {"", {}}, {}, {}},
  {"", {"", {}}, {}, {}},
  {"", {"", {}}, {}, {}},
  {"", {"", {}}, {}, {}},
};


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
  {"���@�̑�", {"�A����", "��̍ޗ�"}},
  {"�R�o���g��", {"�A����","��"}},
  {"�d���̓ő�", {"�A����","�ł̍ޗ�"}},
  {"�~�X�e�B�b�N�n�[�u", {"�A����","�_��̗�","��̍ޗ�"}},
  {"�[�Ă���", {"�A����","�R��"}},
  {"�ܓ��d��", {"�A����","�_��̗�"}},
  {"���ȉ�", {"�A����","���f��","�R��"}},
  {"�ۂނ�������", {"�؍�","�A����"}},
  {"�L�[�t�@", {"�؍�","�A����"}},
  {"�A���^��", {"�A����","��̍ޗ�"}},
  {"�g��", {"�A����","��̍ޗ�"}},
  {"�V���c���N�T", {"�A����","��̍ޗ�"}},
  {"�퐢�̐��", {"�A����","�G���L�V��"}},
  {"�h���P���n�C�g", {"�A����","��̍ޗ�","�G���L�V��"}},
  {"�h���P���V���e����", {"�A����","�ł̍ޗ�","�_��̗�"}},
  {"�A�C�[���z", {"�z��"}},
  {"���C�f���z", {"�z��"}},
  {"�N�v���t�z", {"�z��"}},
  {"�J�[�G����", {"�z��","�Ζ�"}},
  {"�n�N���C��", {"�z��","���"}},
  {"�\�E���X�g��", {"�z��","����"}},
  {"���̔R��", {"�z��","�ł̍ޗ�","�R��"}},
  {"�d���̓y����", {"�S�y","��̍ޗ�"}},
  {"�Β�̓y", {"�S�y"}},
  {"�C��̓y", {"�S�y"}},
  {"�Â��Δ�", {"�z��","�S�y","�_��̗�"}},
  {"�ӂ����΍�", {"�z��","�S�y"}},
  {"�Ñ�̐Β�", {"�z��","�A����"}},
  {"�����Ԃ�b��", {"�z��","�S�y","����"}},
  {"�t�@�[�f�����C�g", {"�z��","���f��"}},
  {"�鐅��", {"�z��","���"}},
  {"�P������", {"�z��","���"}},
  {"��쌋��", {"�z��","�_��̗�"}},
  {"���쌋��", {"�z��","���","�G���L�V��","�_��̗�"}},
  {"�����̉H", {"�����f��","���f��"}},
  {"��v�ȍ�", {"�����f��","��̍ޗ�"}},
  {"�����̃q��", {"�����f��","�H��","��̍ޗ�"}},
  {"�P���m�̖є�", {"�����f��","���f��"}},
  {"�A�J�c�L�̖є�", {"�����f��","���f��"}},
  {"�S��̎�", {"���f��"}},
  {"�S���̍|��", {"���f��"}},
  {"���̃E���R", {"�����f��","��̍ޗ�","�G���L�V��"}},
  {"��ː�", {"��"}},
  {"����������", {"��"}},
  {"�L���w���~���N", {"�H��","��"}},
  {"�����", {"��","�_��̗�"}},
  {"�j�g����", {"�Ζ�","��","�ł̍ޗ�"}},
  {"�d�����t��", {"��","�ł̍ޗ�"}},
  {"�v��̑̉t", {"��","��̍ޗ�"}},
  {"���v��̑̉t", {"��","�_��̗�","��̍ޗ�"}},
  {"���̌���", {"��","�G���L�V��","�ł̍ޗ�"}},
  {"����", {"��","�_��̗�"}},
  {"�v�j�v�j��", {"�H��","�_��̗�"}},
  {"�����̃v�j�v�j��", {"�H��","�_��̗�"}},
  {"����", {"�H��","�A����"}},
  {"�Ԃ���", {"�H��","�A����","�Ζ�"}},
  {"���[������", {"�H��","�A����"}},
  {"���@�C�c�F��", {"�H��","�Ζ�"}},
  {"�y����", {"�H��","�A����"}},
  {"�₢��", {"�H��","����"}},
  {"�n�`�̑�", {"�H��","�Ζ�"}},
  {"���̕s���̃^�}�S", {"�H��","�R��","��̍ޗ�"}},
  {"���܂���C�`�S", {"�H��","�A����"}},
  {"�͂�����x���[", {"�H��","�A����"}},
  {"�j�ꂽ����", {"��","�R��"}},
  {"���R��", {"�R��"}},
  {"�U�t���A��", {"�R��"}},
  {"����̂��D", {"��","�R��"}},
  {"�����Ȃ��D", {"��","�R��"}},
  {"�h�i�ȐM�җp���D", {"��","�R��","���@�̓���"}},
  {"���ꂢ�ȊL�k", {"���","��̍ޗ�"}},
  {"�y�������V�F��", {"���""��̍ޗ�"}},
  {"������", {"���","�z��"}},
  {"���̕�", {"�G���L�V��","�Ζ�"}},
  {"���z�̕�", {"�G���L�V��","�Ζ�"}},
  {"�����̂�����", {"���","�z��"}},
  {"���F�̐�����", {"���","�z��","�_��̗�"}},
  {"�y���f���[�N", {"�_��̗�","���"}},
  {"�y���f�O������", {"�_��̗�","�G���L�V��"}},
  {"�ׂȊj��", {"���","�ł̍ޗ�"}},
  {"���j", {"���","�_��̗�","�G���L�V��"}},
  {"�Y�ꋎ��ꂽ���", {"�؍�"}},
  {"�Y�ꋎ��ꂽ���", {"���"}},
  {"�Y�ꋎ��ꂽ�z��", {"�z��"}},
  {"�Y�ꋎ��ꂽ���i", {"����"}},
  {"�o�����Ȃ��̌���", {"�G���L�V��"}},
  {"�ł�������", {"�G���L�V��"}},
  {"�L������", {"�G���L�V��"}},
  {"�Y��Ȍ���", {"�G���L�V��"}},
  {"���s��̊D", {"�G���L�V��","���@�̓���"}},
  {"�O���̉ԕ�", {"�d�v"}},
  {"�v���̗���", {"�d�v"}},
  {"���͂��߂��y�[�W", {"��","�R��","���@�̓���"}},
  {"�j�ꂽ������", {"���@�̓���","�R��","��"}},
  {"���m�Ȃ�m�̌���", {"��","�R��","�_��̗�"}},
  {"������ꂽ�m�̌���", {"��","�R��","�_��̗�"}},
  {"���ɑ�", {"���e"}},
  {"�t����", {"���e"}},
  {"���w����", {"���e"}},
  {"�h�i�[�X�g�[��", {"���e"}},
  {"�N���t�g", {"���e"}},
  {"�I���t����", {"���e"}},
  {"�V���^�����w����", {"���e"}},
  {"�h�i�[�N���X�^��", {"���e"}},
  {"�v�j�v�j�e", {"���e"}},
  {"�_�̗�����", {"���e","���@�̓���"}},
  {"�����̎��", {"���e","���@�̓���"}},
  {"���@�g���̓J", {"���@�̓���"}},
  {"�V�E�̑�|��", {"���e","���@�̓���"}},
  {"�I���̎��", {"���e","���@�̓���"}},
  {"����g���̓J", {"���@�̓���"}},
  {"�R�t�̖�", {"��i"}},
  {"���t���[���{�g��", {"��i"}},
  {"���敗�̃A���}", {"��i"}},
  {"�����̖�", {"��i","�_��̗�"}},
  {"�_��̗��", {"��i","�G���L�V��"}},
  {"�f�p�ȏĂ��َq", {"�H�i","���َq"}},
  {"�\�e�B�[", {"�H�i","���َq"}},
  {"�v��[���[", {"�H�i","���َq","�_��̗�"}},
  {"�\�t�B�i���V�F", {"�H�i","���َq"}},
  {"�s���\�e�B�[", {"�H�i","�_��̗�"}},
  {"�B���h���b�v", {"�H�i","���َq","���"}},
  {"�v���[�����b�t��", {"�H�i"}},
  {"�x�[�O���T���h", {"�H�i"}},
  {"�ō����z�b�g�~���N", {"�H�i"}},
  {"�n�j�[�V���b�v", {"��i"}},
  {"�V�g�̂����₫", {"���@�̓���"}},
  {"���\�����", {"��i"}},
  {"�s�K�̕r�l��", {"��i"}},
  {"����D��̒�", {"�z"}},
  {"�Η��̋C�t����", {"��i"}},
  {"�����̎ʖ{", {"���@�̓���","��"}},
  {"�������̂�������", {"���@�̓���"}},
  {"�p�Y�~�낵�̊ۖ�", {"��i"}},
  {"�����̔��{", {"���@�̓���","��"}},
  {"���\���i��", {"��i"}},
  {"�d���̓��W", {"���@�̓���"}},
  {"�����Ă�׎�", {"���@�̓���","�؍�"}},
  {"�N���A�h���b�v", {"���@�̓���"}},
  {"�}�i�t�F�U�[", {"���@�̓���","�����f��"}},
  {"���l�̌C", {"�z"}},
  {"�����o�b�N�p�b�N", {"�z"}},
  {"�ً}�ޔ��o�b�O", {"���@�̓���"}},
  {"�E�ݎ��R��", {"�z"}},
  {"���҂̂����", {"���@�̓���"}},
  {"�b�B�̂����", {"���@�̓���"}},
  {"�������̌아", {"���@�̓���","��"}},
  {"�n�[�g�y���_���g", {"����"}},
  {"���a�܁E��", {"���a��"}},
  {"���a�܁E��", {"���a��"}},
  {"���a�܁E��", {"���a��"}},
  {"���a�܁E��", {"���a��"}},
  {"�s���A�E�H�[�^�[", {"��"}},
  {"����̗�", {"��","�_��̗�"}},
  {"�A�v�R�[��", {"�H��","��̍ޗ�"}},
  {"���[��������", {"�H��","�Ζ�"}},
  {"�n�`�~�c", {"�H��"}},
  {"�V�R�y��", {"�H��","�Ζ�","�ł̍ޗ�"}},
  {"����̂���", {"��̍ޗ�","�ł̍ޗ�"}},
  {"�[�b�e��", {"��","�R��"}},
  {"���t���b�V���I�C��", {"�R��","��"}},
  {"����̕�", {"�Ζ�"}},
  {"�u���b�c���C�g", {"����"}},
  {"�K�C�X�g�A�C�[��", {"����","�_��̗�"}},
  {"�B���S�y", {"�S�y","�G���L�V��"}},
  {"���˂�����", {"���f��","����"}},
  {"�X�v���[�X", {"�؍�"}},
  {"�C���S�b�g", {"����f��","����"}},
  {"�V���^�����^��", {"����f��","����"}},
  {"�V�����@���A", {"����f��","����"}},
  {"���r���E��", {"����f��","����"}},
  {"�S���g�A�C�[��", {"����f��","����"}},
  {"�n�����j�E��", {"����f��","����"}},
  {"�N���[�X", {"�h��f��","�z"}},
  {"���t�R�b�g", {"�h��f��","�z"}},
  {"�A�_�[���N���X", {"�h��f��","�z"}},
  {"�t�����[�Q��", {"�h��f��","�z"}},
  {"�t�F�A�n�C�g", {"�h��f��","�z"}},
  {"���F���x�e�B�X", {"�h��f��","�z"}},
  {"��Ԍ���", {"����","���"}},
  {"�m�[�u���T�t�@�C�A", {"���"}},
  {"�[�ł̎�", {"�ł̍ޗ�","��","�R��","�z��"}},
  {"�挩�̐�����", {"���"}},
  {"�H���̗��j��", {"�d�v"}},
  {"�[�g�̐�", {"�����f��","�Ζ�","�G���L�V��","���a��"}},
  {"���҂̐�", {"����","��̍ޗ�","�G���L�V��","�_��̗�"}},
  {"���ւ̎�", {"�_��̗�","�R��","��̍ޗ�","���a��"}},
  {"�~�l�����G�L�X", {"��̍ޗ�","��","����"}},
  {"�΂���ފ����y", {"�S�y"}},
  {"�����ȕ��i", {"����"}},
  {"���΂������̘B����", {"�d�v"}},
  {"���K�p�̘B����", {"�d�v"}},
  {"�����̘B����", {"�d�v"}},
  {"�B�l�̘B����", {"�d�v"}},
  {"�d���̘B����", {"�d�v"}},
  {"�Ñ�̘B����", {"�d�v"}},
  {"�����N���E�X�̓�", {"���@�̓���"}},
  {"�������̐�", {"�d�v"}},
  {"�����̐j", {"�d�v"}},
  {"�^���̌�", {"�d�v"}},
  {"�w�N�Z�E�A�E���X", {"����","���@�̓���"}},
  {"�l�`�t�̎�", {"���f��"}},
  {"����^�h�{��", {"�d�v"}},
  {"�f�[�g��", {"�d�v"}},
  {"���邨����", {"�d�v"}}
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
  cout << "[Error!]:Access to non installed item" << endl;
  return -1;
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
  {"�v��", {18, 5, 6, 1, 1, 0, 0}, {Create_Item("�v�j�v�j��", 1, {1})}, {Create_Item("�v��̑̉t", 1, {1})}, {Create_Item("�����̃v�j�v�j��", 1, {1})}},
  {"�΃v��", {32, 13, 15, 4, 4, 0, 0}, {Create_Item("�v�j�v�j��", 1, {1})}, {Create_Item("�v��̑̉t", 1, {1})}, {Create_Item("�����̃v�j�v�j��", 1, {1})}},
  {"�ԃv��", {54, 21, 25, 7, 8, 0, 0}, {Create_Item("�v�j�v�j��", 1, {1})}, {Create_Item("�v��̑̉t", 1, {1})}, {Create_Item("�����̃v�j�v�j��", 1, {1})}},
  {"���v��", {72, 26, 32, 9, 12, 0, 0}, {Create_Item("�v�j�v�j��", 1, {1})}, {Create_Item("�v��̑̉t", 1, {1})}, {Create_Item("�����̃v�j�v�j��", 1, {1})}},
  {"���v��", {208, 57, 63, 12, 30, 0, 0}, {Create_Item("�v�j�v�j��", 1, {1})}, {Create_Item("�v��̑̉t", 1, {1})}, {Create_Item("�d�����t��", 1, {1}), Create_Item("������", 1, {1}), Create_Item("�y�������V�F��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1})}},
  {"�ՂɂՂɁH", {265, 81, 81, 15, 47, 0, 0}, {Create_Item("�����̃v�j�v�j��", 1, {1})}, {Create_Item("�d�����t��", 1, {1})}, {Create_Item("���C�f���z", 1, {1}), Create_Item("�n�N���C��", 1, {1}), Create_Item("�����Ԃ�b��", 1, {1}), Create_Item("�N�v���t�z", 1, {1})}},
  {"���[�ρ[�Ղ�", {950, 97, 75, 16, 105, 0, 0}, {Create_Item("�����̃v�j�v�j��", 1, {1})}, {Create_Item("���v��̑̉t", 1, {1})}, {}},
  {"���ǂ݂�v��", {2700, 165, 100, 30, 482, 0, 0}, {Create_Item("�����̃v�j�v�j��", 1, {1})}, {Create_Item("���v��̑̉t", 1, {1})}, {}},
  {"�}�W�b�N�u�b�N", {51, 22, 30, 7, 8, 0, 0}, {Create_Item("�j�ꂽ����", 1, {1})}, {Create_Item("�����̂�����", 1, {1})}, {Create_Item("�A�C�[���z", 1, {1}), Create_Item("�J�[�G����", 1, {1}), Create_Item("�Ñ�̐Β�", 1, {1}), Create_Item("���C�f���z", 1, {1})}},
  {"�{�̎g����", {77, 30, 42, 10, 14, 0, 0}, {Create_Item("�j�ꂽ����", 1, {1})}, {Create_Item("�����̂�����", 1, {1})}, {Create_Item("���C�f���z", 1, {1}), Create_Item("�n�N���C��", 1, {1}), Create_Item("�����Ԃ�b��", 1, {1}), Create_Item("�N�v���t�z", 1, {1})}},
  {"�����Ă閂�p��", {228, 62, 72, 14, 37, 0, 0}, {Create_Item("�j�ꂽ����", 1, {1})}, {Create_Item("�鐅��", 1, {1})}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1})}},
  {"�֒f�̎ʖ{", {454, 104, 77, 18, 74, 0, 0}, {Create_Item("�j�ꂽ����", 1, {1})}, {Create_Item("���F�̐�����", 1, {1})}, {Create_Item("���r���E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1})}},
  {"���b�`�I�[�_�[", {1392, 154, 97, 20, 185, 0, 0}, {Create_Item("���F�̐�����", 1, {1})}, {Create_Item("�h�i�ȐM�җp���D", 1, {1})}, {Create_Item("���r���E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1})}},
  {"�����̒q��", {1512, 109, 102, 21, 203, 0, 0}, {Create_Item("���F�̐�����", 1, {1})}, {}, {Create_Item("���̃E���R", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("���̌���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1}), Create_Item("�n�����j�E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1})}},
  {"�S�[�X�g", {12, 15, 4, 4, 3, 0, 0}, {Create_Item("�����̂�����", 1, {1})}, {Create_Item("�y���f���[�N", 1, {1})}, {}},
  {"�X�J�[���f�B", {21, 24, 6, 7, 6, 0, 0}, {Create_Item("�����̂�����", 1, {1})}, {Create_Item("�y���f���[�N", 1, {1})}, {}},
  {"�W�F���g���t�@���g��", {82, 34, 8, 10, 13, 0, 0}, {Create_Item("�����̂�����", 1, {1})}, {Create_Item("�y���f���[�N", 1, {1})}, {}},
  {"�z�[���g", {183, 75, 15, 15, 33, 0, 0}, {Create_Item("�y���f���[�N", 1, {1})}, {}, {Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("����", 1, {1}), Create_Item("����̂��D", 1, {1}), Create_Item("�����Ȃ��D", 1, {1}), Create_Item("�h�i�ȐM�җp���D", 1, {1})}},
  {"�t�@�j�[�t�F�C�X", {1192, 152, 107, 19, 161, 0, 0}, {Create_Item("�����̂�����", 1, {1})}, {}, {Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"�����̉���", {1530, 121, 127, 22, 219, 0, 0}, {Create_Item("�����̂�����", 1, {1})}, {}, {Create_Item("���r���E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1})}},
  {"�}���h���S��", {60, 14, 0, 4, 4, 0, 0}, {Create_Item("���@�̑�", 1, {1})}, {}, {Create_Item("���[������", 1, {1}), Create_Item("����", 1, {1}), Create_Item("�y����", 1, {1})}},
  {"�z���C�g���[�g", {119, 26, 0, 8, 11, 0, 0}, {Create_Item("���@�̑�", 1, {1})}, {Create_Item("�R�o���g��", 1, {1}), Create_Item("�[�Ă���", 1, {1}), Create_Item("�Ԃ���", 1, {1}), Create_Item("�ۂނ�������", 1, {1})}, {Create_Item("�d���̓ő�", 1, {1}), Create_Item("�ܓ��d��", 1, {1}), Create_Item("���ȉ�", 1, {1}), Create_Item("�͂�����x���[", 1, {1})}},
  {"�A�����E�l", {204, 53, 0, 12, 24, 0, 0}, {Create_Item("���@�̑�", 1, {1})}, {Create_Item("�d���̓ő�", 1, {1}), Create_Item("�ܓ��d��", 1, {1}), Create_Item("���ȉ�", 1, {1}), Create_Item("�͂�����x���[", 1, {1})}, {Create_Item("�R�o���g��", 1, {1}), Create_Item("�[�Ă���", 1, {1}), Create_Item("�Ԃ���", 1, {1}), Create_Item("�ۂނ�������", 1, {1})}},
  {"�L�����N�W��", {573, 78, 0, 16, 65, 0, 0}, {Create_Item("���@�̑�", 1, {1})}, {Create_Item("�R�o���g��", 1, {1}), Create_Item("�[�Ă���", 1, {1}), Create_Item("�Ԃ���", 1, {1}), Create_Item("�ۂނ�������", 1, {1})}, {Create_Item("�~�X�e�B�b�N�n�[�u", 1, {1}), Create_Item("�₢��", 1, {1}), Create_Item("�h���P���V���e����", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1})}},
  {"�����Ԃ̐�", {1072, 75, 0, 15, 95, 0, 0}, {Create_Item("�h���P���V���e����", 1, {1})}, {Create_Item("�d���̓ő�", 1, {1}), Create_Item("�ܓ��d��", 1, {1}), Create_Item("���ȉ�", 1, {1}), Create_Item("�͂�����x���[", 1, {1})}, {Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"�i�C�g�V�F�C�h", {2048, 114, 0, 21, 247, 0, 0}, {Create_Item("�h���P���V���e����", 1, {1})}, {Create_Item("�~�X�e�B�b�N�n�[�u", 1, {1}), Create_Item("�₢��", 1, {1}), Create_Item("�h���P���V���e����", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1})}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1})}},
  {"�K�[�S�C��", {55, 20, 22, 5, 6, 0, 0}, {Create_Item("�A�C�[���z", 1, {1})}, {}, {Create_Item("�Â��Δ�", 1, {1}), Create_Item("�ӂ����΍�", 1, {1}), Create_Item("�J�[�G����", 1, {1})}},
  {"�A�|�X�e��", {110, 33, 37, 9, 17, 0, 0}, {Create_Item("�Â��Δ�", 1, {1}), Create_Item("�ӂ����΍�", 1, {1}), Create_Item("�A�C�[���z", 1, {1})}, {}, {Create_Item("�J�[�G����", 1, {1})}},
  {"�~�j�f�[����", {286, 68, 65, 13, 45, 0, 0}, {Create_Item("�A�C�[���z", 1, {1})}, {Create_Item("�J�[�G����", 1, {1}), Create_Item("�Ñ�̐Β�", 1, {1})}, {Create_Item("���C�f���z", 1, {1}), Create_Item("�n�`�̑�", 1, {1}), Create_Item("�P���m�̖є�", 1, {1}), Create_Item("��v�ȍ�", 1, {1}), Create_Item("���R��", 1, {1})}},
  {"�g���b�J�[", {614, 111, 93, 19, 115, 0, 0}, {Create_Item("���C�f���z", 1, {1})}, {Create_Item("�n�N���C��", 1, {1}), Create_Item("�����Ԃ�b��", 1, {1}), Create_Item("�N�v���t�z", 1, {1})}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1})}},
  {"�f�r���z�[��", {1626, 130, 94, 20, 251, 0, 0}, {Create_Item("�ׂȊj��", 1, {1})}, {Create_Item("�N�v���t�z", 1, {1}), Create_Item("�\�E���X�g��", 1, {1}), Create_Item("���̔R��", 1, {1})}, {Create_Item("�Y�ꋎ��ꂽ�z��", 1, {1})}},
  {"���󂳂ꂵ����", {2188, 161, 121, 24, 395, 0, 0}, {Create_Item("�ׂȊj��", 1, {1})}, {Create_Item("�N�v���t�z", 1, {1}), Create_Item("�\�E���X�g��", 1, {1}), Create_Item("���̔R��", 1, {1})}, {Create_Item("�Y�ꋎ��ꂽ�z��", 1, {1}), Create_Item("�n�����j�E��", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("���v��̑̉t", 1, {1}), Create_Item("�h�i�ȐM�җp���D", 1, {1}), Create_Item("�y���f�O������", 1, {1}), Create_Item("�h���P���V���e����", 1, {1}), Create_Item("��쌋��", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1})}},
  {"�A�[�h��", {50, 21, 21, 6, 8, 0, 0}, {Create_Item("�����̉H", 1, {1})}, {}, {Create_Item("�n�`�̑�", 1, {1}), Create_Item("�P���m�̖є�", 1, {1}), Create_Item("��v�ȍ�", 1, {1}), Create_Item("���R��", 1, {1})}},
  {"�J�C�[���s�W����", {79, 30, 30, 9, 15, 0, 0}, {Create_Item("�����̉H", 1, {1})}, {Create_Item("���̕s���̃^�}�S", 1, {1}), Create_Item("���ꂢ�ȊL�k", 1, {1}), Create_Item("�S��̎�", 1, {1}), Create_Item("�U�t���A��", 1, {1})}, {Create_Item("�d�����t��", 1, {1}), Create_Item("������", 1, {1}), Create_Item("�y�������V�F��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1})}},
  {"�Z�C�o�[�N���E", {234, 61, 54, 13, 41, 0, 0}, {Create_Item("�����̉H", 1, {1})}, {Create_Item("�d�����t��", 1, {1}), Create_Item("������", 1, {1}), Create_Item("�y�������V�F��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1})}, {Create_Item("���̕s���̃^�}�S", 1, {1}), Create_Item("���ꂢ�ȊL�k", 1, {1}), Create_Item("�S��̎�", 1, {1}), Create_Item("�U�t���A��", 1, {1})}},
  {"�O�X�^�t", {438, 81, 65, 16, 76, 0, 0}, {Create_Item("�����̉H", 1, {1})}, {Create_Item("���̕s���̃^�}�S", 1, {1}), Create_Item("���ꂢ�ȊL�k", 1, {1}), Create_Item("�S��̎�", 1, {1}), Create_Item("�U�t���A��", 1, {1})}, {Create_Item("�d�����t��", 1, {1}), Create_Item("������", 1, {1}), Create_Item("�y�������V�F��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1})}},
  {"���b�N", {1564, 124, 81, 20, 241, 0, 0}, {Create_Item("�����̉H", 1, {1})}, {}, {Create_Item("���̃E���R", 1, {1}), Create_Item("���F�̐�����", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("���̌���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1})}},
  {"���V�̗쒹", {1968, 88, 78, 23, 327, 0, 0}, {Create_Item("�����̉H", 1, {1})}, {Create_Item("�t�@�[�f�����C�g", 1, {1})}, {Create_Item("���̕�", 1, {1})}},
  {"�L�����r�[�X�g", {126, 33, 28, 8, 19, 0, 0}, {Create_Item("�P���m�̖є�", 1, {1})}, {Create_Item("��v�ȍ�", 1, {1})}, {Create_Item("�n�`�̑�", 1, {1}), Create_Item("���R��", 1, {1})}},
  {"���C�g�j���O", {216, 53, 41, 12, 41, 0, 0}, {Create_Item("�P���m�̖є�", 1, {1})}, {Create_Item("��v�ȍ�", 1, {1})}, {Create_Item("�d�����t��", 1, {1}), Create_Item("������", 1, {1}), Create_Item("�y�������V�F��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1})}},
  {"�t�@���O", {442, 98, 68, 16, 96, 0, 0}, {Create_Item("��v�ȍ�", 1, {1})}, {Create_Item("�A�J�c�L�̖є�", 1, {1})}, {Create_Item("���̕s���̃^�}�S", 1, {1}), Create_Item("���ꂢ�ȊL�k", 1, {1}), Create_Item("�S��̎�", 1, {1}), Create_Item("�U�t���A��", 1, {1})}},
  {"�c�C���w�b�_�[", {772, 129, 84, 20, 181, 0, 0}, {Create_Item("��v�ȍ�", 1, {1})}, {Create_Item("�A�J�c�L�̖є�", 1, {1})}, {Create_Item("���̃E���R", 1, {1}), Create_Item("���F�̐�����", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("���̌���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1})}},
  {"���ق̖��b", {400, 60, 43, 10, 49, 0, 0}, {Create_Item("�A�J�c�L�̖є�", 1, {1})}, {}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1}), Create_Item("�d�����t��", 1, {1}), Create_Item("������", 1, {1}), Create_Item("�y�������V�F��", 1, {1})}},
  {"�g�@�̉�", {2530, 104, 76, 22, 484, 0, 0}, {Create_Item("�A�J�c�L�̖є�", 1, {1})}, {Create_Item("���r���E��", 1, {1})}, {Create_Item("���z�̕�", 1, {1})}},
  {"����", {106, 33, 33, 9, 21, 0, 0}, {Create_Item("�����̃q��", 1, {1})}, {Create_Item("��v�ȍ�", 1, {1})}, {Create_Item("�Β�̓y", 1, {1})}},
  {"��{�p", {158, 48, 43, 12, 36, 0, 0}, {Create_Item("�����̃q��", 1, {1})}, {Create_Item("��v�ȍ�", 1, {1})}, {Create_Item("���@�̑�", 1, {1}), Create_Item("���[������", 1, {1}), Create_Item("����", 1, {1}), Create_Item("�y����", 1, {1})}},
  {"�启��", {351, 88, 71, 16, 85, 0, 0}, {Create_Item("�����̃q��", 1, {1})}, {}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1}), Create_Item("�d���̓ő�", 1, {1}), Create_Item("�ܓ��d��", 1, {1}), Create_Item("���ȉ�", 1, {1}), Create_Item("�͂�����x���[", 1, {1})}},
  {"�^�C�����g�z����", {600, 110, 84, 19, 145, 0, 0}, {Create_Item("�����̃q��", 1, {1})}, {}, {Create_Item("���r���E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("�d���̓ő�", 1, {1}), Create_Item("�ܓ��d��", 1, {1}), Create_Item("���ȉ�", 1, {1}), Create_Item("�͂�����x���[", 1, {1})}},
  {"�C�T�i�V�E�X", {1966, 163, 100, 21, 520, 0, 0}, {Create_Item("�����̃q��", 1, {1})}, {Create_Item("�Β�̓y", 1, {1})}, {Create_Item("�y�������V�F��", 1, {1})}},
  {"�O�����h�I�[�V����", {4000, 200, 131, 25, 1154, 0, 0}, {Create_Item("�����̃q��", 1, {1})}, {Create_Item("�C��̓y", 1, {1})}, {Create_Item("�Y�ꋎ��ꂽ���", 1, {1})}},
  {"���b�`", {158, 58, 57, 12, 37, 0, 0}, {Create_Item("�y���f���[�N", 1, {1})}, {}, {}},
  {"�V���h�E", {198, 72, 66, 14, 51, 0, 0}, {Create_Item("�y���f���[�N", 1, {1})}, {}, {}},
  {"���̐R�⊯", {384, 116, 99, 17, 100, 0, 0}, {Create_Item("�y���f���[�N", 1, {1})}, {}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1})}},
  {"�A�[�N���b�`", {600, 133, 111, 19, 148, 0, 0}, {Create_Item("�y���f���[�N", 1, {1})}, {}, {Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"���p�t�^�C�^�X", {1966, 287, 150, 24, 474, 0, 0}, {Create_Item("�~�X�e�B�b�N�n�[�u", 1, {1}), Create_Item("�₢��", 1, {1})}, {Create_Item("�h���P���V���e����", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1})}, {Create_Item("���̃E���R", 1, {1}), Create_Item("���F�̐�����", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("���̌���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1}), Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"�m�[���C�t�L���O", {999, 116, 94, 16, 167, 0, 0}, {}, {}, {Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("����", 1, {1}), Create_Item("����̂��D", 1, {1}), Create_Item("�����Ȃ��D", 1, {1}), Create_Item("�h�i�ȐM�җp���D", 1, {1})}},
  {"�t���A�f�[����", {146, 42, 42, 10, 27, 0, 0}, {Create_Item("�ׂȊj��", 1, {1})}, {}, {}},
  {"�T���_���X", {219, 62, 54, 13, 48, 0, 0}, {Create_Item("�ׂȊj��", 1, {1})}, {}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1})}},
  {"�w���Q�[�g", {433, 111, 89, 16, 133, 0, 0}, {Create_Item("�ׂȊj��", 1, {1})}, {}, {Create_Item("�C���S�b�g", 1, {1}), Create_Item("�V���^�����^��", 1, {1}), Create_Item("�N���[�X", 1, {1}), Create_Item("���t�R�b�g", 1, {1}), Create_Item("�V�����@���A", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�A�_�[���N���X", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"�O���[�g�f�[����", {759, 147, 111, 20, 249, 0, 0}, {Create_Item("�ׂȊj��", 1, {1})}, {}, {Create_Item("�n�����j�E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"�C�t���[�^", {2712, 212, 121, 21, 690, 0, 0}, {}, {}, {Create_Item("�n�����j�E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("���̃E���R", 1, {1}), Create_Item("���F�̐�����", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("���̌���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1})}},
  {"�e���y�X�^�X", {3238, 199, 150, 24, 925, 0, 0}, {}, {}, {Create_Item("���̃E���R", 1, {1}), Create_Item("���F�̐�����", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("���̌���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1}), Create_Item("�n�����j�E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�����[�Q��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1})}},
  {"�h���S�l�A", {1500, 185, 98, 20, 600, 0, 0}, {Create_Item("���̃E���R", 1, {1})}, {Create_Item("���̌���", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�t�@�[�f�����C�g", 1, {1}), Create_Item("�P������", 1, {1}), Create_Item("�Ñ�̐Β�", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1}), Create_Item("�����", 1, {1}), Create_Item("�j�g����", 1, {1})}, {Create_Item("���j", 1, {1}), Create_Item("�n�����j�E��", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("���z�̕�", 1, {1}), Create_Item("���̕�", 1, {1}), Create_Item("�Y��Ȍ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ�z��", 1, {1})}},
  {"�}�O�}�V�E�X", {2000, 241, 134, 25, 1000, 0, 0}, {Create_Item("���̃E���R", 1, {1})}, {Create_Item("���̌���", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�t�@�[�f�����C�g", 1, {1}), Create_Item("�P������", 1, {1}), Create_Item("�Ñ�̐Β�", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1}), Create_Item("�����", 1, {1}), Create_Item("�j�g����", 1, {1})}, {Create_Item("���j", 1, {1}), Create_Item("�n�����j�E��", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("���z�̕�", 1, {1}), Create_Item("���̕�", 1, {1}), Create_Item("�Y��Ȍ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ�z��", 1, {1})}},
  {"���z���q���҃��V���N", {4000, 209, 140, 25, 1700, 0, 0}, {Create_Item("���̃E���R", 1, {1})}, {Create_Item("���̌���", 1, {1})}, {Create_Item("���j", 1, {1})}},
  {"�����P���҃h�D���N", {3000, 241, 134, 25, 1400, 0, 0}, {Create_Item("���̃E���R", 1, {1})}, {Create_Item("���̌���", 1, {1})}, {Create_Item("���j", 1, {1})}},
  {"���̃G�������^��", {1000, 103, 84, 18, 400, 0, 0}, {}, {Create_Item("�y���f�O������", 1, {1}), Create_Item("��쌋��", 1, {1}), Create_Item("���쌋��", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1}), Create_Item("�ł�������", 1, {1}), Create_Item("���F�̐�����", 1, {1})}, {}},
  {"�X�̃G�������^��", {2000, 227, 124, 23, 900, 0, 0}, {}, {Create_Item("�y���f�O������", 1, {1}), Create_Item("��쌋��", 1, {1}), Create_Item("���쌋��", 1, {1}), Create_Item("���r���E��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("�S���̍|��", 1, {1}), Create_Item("�A�J�c�L�̖є�", 1, {1}), Create_Item("�ł�������", 1, {1}), Create_Item("���F�̐�����", 1, {1})}, {Create_Item("�n�����j�E��", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("�h���P���V���e����", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1})}},
  {"���̃G�������^��", {4444, 240, 206, 28, 2200, 0, 0}, {}, {Create_Item("�y���f�O������", 1, {1}), Create_Item("��쌋��", 1, {1}), Create_Item("���쌋��", 1, {1}), Create_Item("�n�����j�E��", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("�h���P���V���e����", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���", 1, {1})}, {}},
  {"����", {6000, 257, 198, 30, 3000, 0, 0}, {Create_Item("���r���E��", 1, {1}), Create_Item("�t�@�[�f�����C�g", 1, {1}), Create_Item("�j�g����", 1, {1}), Create_Item("�����", 1, {1}), Create_Item("�Ñ�̐Β�", 1, {1}), Create_Item("�y���f���[�N", 1, {1}), Create_Item("�ׂȊj��", 1, {1}), Create_Item("�ł�������", 1, {1}), Create_Item("�L������", 1, {1})}, {Create_Item("�n�����j�E��", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1}), Create_Item("���v��̑̉t", 1, {1}), Create_Item("�h�i�ȐM�җp���D", 1, {1}), Create_Item("�y���f�O������", 1, {1}), Create_Item("�h���P���V���e����", 1, {1}), Create_Item("��쌋��", 1, {1}), Create_Item("�Y�ꋎ��ꂽ���i", 1, {1}), Create_Item("�Y�ꋎ��ꂽ�z��", 1, {1})}, {}},
  {"���b���e�B�I�O����", {2000, 159, 137, 22, 800, 0, 0}, {}, {}, {}},
  {"�i�U���X", {2000, 160, 79, 20, 700, 0, 0}, {Create_Item("�[�g�̐�", 1, {1})}, {}, {}},
  {"���A�[�h", {3000, 169, 128, 25, 1300, 0, 0}, {Create_Item("���҂̐�", 1, {1})}, {}, {Create_Item("�n�����j�E��", 1, {1}), Create_Item("�S���g�A�C�[��", 1, {1}), Create_Item("�t�F�A�n�C�g", 1, {1}), Create_Item("���F���x�e�B�X", 1, {1})}},
  {"�������C�V���A�k�X", {5000, 400, 250, 30, 5000, 0, 0}, {}, {}, {}}
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
  {Create_Item("���ɑ�", 1, {1}), {Create_Material("�Ζ�", 1, {}), Create_Material("�z��", 1, {})}},
  {Create_Item("�t����", 1, {1}), {Create_Material("�J�[�G����", 2, {}), Create_Material("�Ζ�", 1, {}), Create_Material("��", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("���w����", 1, {1}), {Create_Material("�n�N���C��", 2, {}), Create_Material("��", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�h�i�[�X�g�[��", 1, {1}), {Create_Material("���C�f���z", 2, {}), Create_Material("�S�y", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�N���t�g", 1, {1}), {Create_Material("���ɑ�", 1, {}), Create_Material("����", 2, {}), Create_Material("�Ζ�", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�I���t����", 1, {1}), {Create_Material("�t����", 1, {}), Create_Material("����̕�", 1, {}), Create_Material("�Ζ�", 2, {}), Create_Material("���a��", 2, {})}},
  {Create_Item("�V���^�����w����", 1, {1}), {Create_Material("���w����", 1, {}), Create_Material("��Ԍ���", 2, {}), Create_Material("��", 2, {}), Create_Material("���a��", 2, {})}},
  {Create_Item("�h�i�[�N���X�^��", 1, {1}), {Create_Material("�h�i�[�X�g�[��", 1, {}), Create_Material("�u���b�c���C�g", 2, {}), Create_Material("���", 2, {}), Create_Material("����", 2, {})}},
  {Create_Item("�v�j�v�j�e", 1, {1}), {Create_Material("�V���^�����^��", 1, {}), Create_Material("�v�j�v�j��", 4, {}), Create_Material("�Ζ�", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�_�̗�����", 1, {1}), {Create_Material("�m�[�u���T�t�@�C�A", 1, {}), Create_Material("�ׂȊj��", 3, {}), Create_Material("���e", 1, {}), Create_Material("����", 2, {})}},
  {Create_Item("�����̎��", 1, {1}), {Create_Material("�[�g�̐�", 1, {}), Create_Material("���̕�", 3, {}), Create_Material("���e", 1, {}), Create_Material("�_��̗�", 2, {})}},
  {Create_Item("���@�g���̓J", 1, {1}), {Create_Material("�X�v���[�X", 2, {}), Create_Material("�V�g�̂����₫", 1, {}), Create_Material("�����f��", 2, {}), Create_Material("���f��", 2, {})}},
  {Create_Item("�V�E�̑�|��", 1, {1}), {Create_Material("�m�[�u���T�t�@�C�A", 1, {}), Create_Material("���j", 1, {}), Create_Material("���e", 2, {}), Create_Material("����", 2, {})}},
  {Create_Item("�I���̎��", 1, {1}), {Create_Material("�[�g�̐�", 1, {}), Create_Material("���z�̕�", 2, {}), Create_Material("���e", 2, {}), Create_Material("�_��̗�", 2, {})}},
  {Create_Item("����g���̓J", 1, {1}), {Create_Material("�X�v���[�X", 2, {}), Create_Material("�������̂�������", 1, {}), Create_Material("�����f��", 3, {}), Create_Material("���f��", 2, {})}},
  {Create_Item("�R�t�̖�", 1, {1}), {Create_Material("���@�̑�", 2, {}), Create_Material("�����f��", 1, {}), Create_Material("��", 1, {})}},
  {Create_Item("���t���[���{�g��", 1, {1}), {Create_Material("�R�o���g��", 2, {}), Create_Material("��̍ޗ�", 2, {}), Create_Material("��", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("���敗�̃A���}", 1, {1}), {Create_Material("���t���b�V���I�C��", 1, {}), Create_Material("��̍ޗ�", 2, {}), Create_Material("��", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�����̖�", 1, {1}), {Create_Material("�~�X�e�B�b�N�n�[�u", 2, {}), Create_Material("�G���L�V��", 2, {}), Create_Material("�_��̗�", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�_��̗��", 1, {1}), {Create_Material("�h���P���n�C�g", 1, {}), Create_Material("�G���L�V��", 2, {}), Create_Material("��", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�f�p�ȏĂ��َq", 1, {1}), {Create_Material("����", 2, {}), Create_Material("��", 1, {}), Create_Material("�A����", 1, {})}},
  {Create_Item("�\�e�B�[", 1, {1}), {Create_Material("�A����", 1, {}), Create_Material("�R��", 2, {}), Create_Material("��", 1, {})}},
  {Create_Item("�v��[���[", 1, {1}), {Create_Material("�v�j�v�j��", 2, {}), Create_Material("��", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�\�t�B�i���V�F", 1, {1}), {Create_Material("���[��������", 3, {}), Create_Material("�V�R�y��", 1, {}), Create_Material("�H��", 2, {}), Create_Material("��", 1, {})}},
  {Create_Item("�s���\�e�B�[", 1, {1}), {Create_Material("�~�X�e�B�b�N�n�[�u", 2, {}), Create_Material("�s���A�E�H�[�^�[", 1, {}), Create_Material("��", 2, {}), Create_Material("��", 1, {})}},
  {Create_Item("�B���h���b�v", 1, {1}), {Create_Material("���܂���C�`�S", 3, {}), Create_Material("�n�`�~�c", 2, {}), Create_Material("��", 1, {})}},
  {Create_Item("�v���[�����b�t��", 1, {1}), {Create_Material("���[��������", 2, {}), Create_Material("�n�j�[�V���b�v", 2, {}), Create_Material("�ō����z�b�g�~���N", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�x�[�O���T���h", 1, {1}), {Create_Material("���[��������", 2, {}), Create_Material("�H��", 2, {}), Create_Material("��", 1, {}), Create_Material("��", 1, {})}},
  {Create_Item("�ō����z�b�g�~���N", 1, {1}), {Create_Material("�L���w���~���N", 2, {}), Create_Material("�R��", 2, {}), Create_Material("��̍ޗ�", 1, {})}},
  {Create_Item("�n�j�[�V���b�v", 1, {1}), {Create_Material("�n�`�~�c", 1, {}), Create_Material("��i", 1, {}), Create_Material("��", 2, {})}},
  {Create_Item("�V�g�̂����₫", 1, {1}), {Create_Material("����", 2, {}), Create_Material("�y���f���[�N", 2, {}), Create_Material("����", 1, {}), Create_Material("�S�y", 1, {})}},
  {Create_Item("���\�����", 1, {1}), {Create_Material("����̂���", 1, {}), Create_Material("�A����", 3, {}), Create_Material("��", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("�s�K�̕r�l��", 1, {1}), {Create_Material("�d�����t��", 1, {}), Create_Material("�y���f���[�N", 1, {}), Create_Material("�����f��", 2, {}), Create_Material("��", 2, {})}},
  {Create_Item("����D��̒�", 1, {1}), {Create_Material("�S��̎�", 2, {}), Create_Material("�z", 2, {}), Create_Material("���f��", 1, {}), Create_Material("�_��̗�", 2, {})}},
  {Create_Item("�Η��̋C�t����", 1, {1}), {Create_Material("���̌���", 1, {}), Create_Material("�Ζ�", 2, {}), Create_Material("��", 2, {})}},
  {Create_Item("�����̎ʖ{", 1, {1}), {Create_Material("�[�b�e��", 2, {}), Create_Material("�y���f���[�N", 1, {}), Create_Material("���f��", 2, {}), Create_Material("�_��̗�", 2, {})}},
  {Create_Item("�������̂�������", 1, {1}), {Create_Material("�d�����t��", 1, {}), Create_Material("�ł̍ޗ�", 2, {}), Create_Material("����", 1, {}), Create_Material("�_��̗�", 2, {})}},
  {Create_Item("�p�Y�~�낵�̊ۖ�", 1, {1}), {Create_Material("���̃E���R", 2, {}), Create_Material("�G���L�V��", 2, {}), Create_Material("�H��", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�����̔��{", 1, {1}), {Create_Material("��", 3, {}), Create_Material("�y���f�O������", 1, {}), Create_Material("�����f��", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("���\���i��", 1, {1}), {Create_Material("�A����", 3, {}), Create_Material("��̍ޗ�", 1, {}), Create_Material("��", 2, {})}},
  {Create_Item("�d���̓��W", 1, {1}), {Create_Material("�؍�", 2, {}), Create_Material("����", 1, {}), Create_Material("��", 2, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�����Ă�׎�", 1, {1}), {Create_Material("�X�v���[�X", 2, {}), Create_Material("���f��", 1, {}), Create_Material("����", 1, {})}},
  {Create_Item("�N���A�h���b�v", 1, {1}), {Create_Material("�B���h���b�v", 2, {}), Create_Material("�H��", 1, {}), Create_Material("��", 2, {})}},
  {Create_Item("�}�i�t�F�U�[", 1, {1}), {Create_Material("�����̉H", 2, {}), Create_Material("���@�̓���", 2, {}), Create_Material("���f��", 1, {})}},
  {Create_Item("���l�̌C", 1, {1}), {Create_Material("�����f��", 2, {}), Create_Material("���f��", 2, {}), Create_Material("����", 1, {})}},
  {Create_Item("�����o�b�N�p�b�N", 1, {1}), {Create_Material("�P���m�̖є�", 3, {}), Create_Material("�_��̗�", 2, {}), Create_Material("���f��", 1, {})}},
  {Create_Item("�ً}�ޔ��o�b�O", 1, {1}), {Create_Material("�z", 2, {}), Create_Material("���f��", 2, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�E�ݎ��R��", 1, {1}), {Create_Material("�����f��", 2, {}), Create_Material("�A����", 1, {}), Create_Material("���f��", 1, {})}},
  {Create_Item("���҂̂����", 1, {1}), {Create_Material("�����Ȃ��D", 1, {}), Create_Material("��", 2, {}), Create_Material("�z", 1, {})}},
  {Create_Item("�b�B�̂����", 1, {1}), {Create_Material("�����Ȃ��D", 1, {}), Create_Material("�؍�", 2, {}), Create_Material("�z", 1, {})}},
  {Create_Item("�������̌아", 1, {1}), {Create_Material("�h�i�ȐM�җp���D", 1, {}), Create_Material("����", 2, {}), Create_Material("�z", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�n�[�g�y���_���g", 1, {1}), {Create_Material("������", 2, {}), Create_Material("����", 1, {}), Create_Material("���", 1, {})}},
  {Create_Item("���a�܁E��", 5, {1}), {Create_Material("�Ζ�", 2, {}), Create_Material("��", 2, {})}},
  {Create_Item("���a�܁E��", 5, {1}), {Create_Material("�z��", 2, {}), Create_Material("��", 2, {})}},
  {Create_Item("���a�܁E��", 5, {1}), {Create_Material("�A����", 2, {}), Create_Material("��", 2, {})}},
  {Create_Item("���a�܁E��", 5, {1}), {Create_Material("�S�y", 2, {}), Create_Material("��", 2, {})}},
  {Create_Item("�s���A�E�H�[�^�[", 4, {1}), {Create_Material("���ȉ�", 1, {}), Create_Material("�L�[�t�@", 2, {}), Create_Material("��", 1, {}), Create_Material("�z��", 1, {})}},
  {Create_Item("����̗�", 3, {1}), {Create_Material("��쌋��", 2, {}), Create_Material("�����̂�����", 2, {}), Create_Material("�s���A�E�H�[�^�[", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�A�v�R�[��", 3, {1}), {Create_Material("���܂���C�`�S", 2, {}), Create_Material("�A����", 1, {}), Create_Material("��", 1, {})}},
  {Create_Item("���[��������", 4, {1}), {Create_Material("���[������", 3, {}), Create_Material("��", 1, {}), Create_Material("�z��", 1, {})}},
  {Create_Item("�n�`�~�c", 3, {1}), {Create_Material("�n�`�̑�", 2, {}), Create_Material("���a��", 2, {})}},
  {Create_Item("�V�R�y��", 3, {1}), {Create_Material("�y����", 2, {}), Create_Material("�A����", 2, {}), Create_Material("��̍ޗ�", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("����̂���", 3, {1}), {Create_Material("���@�̑�", 5, {}), Create_Material("�ł̍ޗ�", 1, {}), Create_Material("��̍ޗ�", 1, {}), Create_Material("�G���L�V��", 1, {})}},
  {Create_Item("�[�b�e��", 4, {1}), {Create_Material("�A����", 3, {}), Create_Material("��", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("���t���b�V���I�C��", 3, {1}), {Create_Material("���R��", 2, {}), Create_Material("�A����", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("����̕�", 2, {1}), {Create_Material("�J�[�G����", 3, {}), Create_Material("���̔R��", 1, {}), Create_Material("�Ζ�", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�u���b�c���C�g", 3, {1}), {Create_Material("���C�f���z", 2, {}), Create_Material("�j�g����", 1, {}), Create_Material("�z��", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�K�C�X�g�A�C�[��", 3, {1}), {Create_Material("��쌋��", 1, {}), Create_Material("�Ñ�̐Β�", 2, {}), Create_Material("�_��̗�", 1, {}), Create_Material("�z��", 1, {})}},
  {Create_Item("�B���S�y", 2, {1}), {Create_Material("�S�y", 4, {}), Create_Material("�_��̗�", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("���˂�����", 4, {1}), {Create_Material("�S��̎�", 2, {}), Create_Material("����", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("�X�v���[�X", 3, {1}), {Create_Material("�L�[�t�@", 3, {}), Create_Material("�؍�", 1, {}), Create_Material("�z", 1, {})}},
  {Create_Item("�C���S�b�g", 2, {1}), {Create_Material("�z��", 3, {}), Create_Material("�R��", 2, {})}},
  {Create_Item("�V���^�����^��", 2, {1}), {Create_Material("���C�f���z", 3, {}), Create_Material("�A�C�[���z", 1, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("�V�����@���A", 2, {1}), {Create_Material("�N�v���t�z", 2, {}), Create_Material("�\�E���X�g��", 1, {}), Create_Material("�z��", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("���r���E��", 2, {1}), {Create_Material("�����Ԃ�b��", 1, {}), Create_Material("���̔R��", 2, {}), Create_Material("�z��", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("�S���g�A�C�[��", 2, {1}), {Create_Material("�K�C�X�g�A�C�[��", 1, {}), Create_Material("�ӂ����΍�", 2, {}), Create_Material("�z��", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("�n�����j�E��", 2, {1}), {Create_Material("�[�g�̐�", 1, {}), Create_Material("���쌋��", 2, {}), Create_Material("�z��", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("�N���[�X", 2, {1}), {Create_Material("���f��", 2, {}), Create_Material("�A����", 1, {}), Create_Material("�����f��", 1, {})}},
  {Create_Item("���t�R�b�g", 2, {1}), {Create_Material("���ȉ�", 2, {}), Create_Material("�A����", 1, {}), Create_Material("���f��", 1, {}), Create_Material("�����f��", 1, {})}},
  {Create_Item("�A�_�[���N���X", 2, {1}), {Create_Material("�S��̎�", 2, {}), Create_Material("�P���m�̖є�", 2, {}), Create_Material("�A����", 1, {}), Create_Material("��", 1, {})}},
  {Create_Item("�t�����[�Q��", 2, {1}), {Create_Material("�t�@�[�f�����C�g", 1, {}), Create_Material("���f��", 2, {}), Create_Material("�����f��", 2, {}), Create_Material("��", 1, {})}},
  {Create_Item("�t�F�A�n�C�g", 2, {1}), {Create_Material("���˂�����", 1, {}), Create_Material("�s���A�E�H�[�^�[", 2, {}), Create_Material("���f��", 2, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("���F���x�e�B�X", 2, {1}), {Create_Material("�S���̍|��", 2, {}), Create_Material("���v��̑̉t", 3, {}), Create_Material("�A����", 1, {}), Create_Material("�G���L�V��", 1, {})}},
  {Create_Item("��Ԍ���", 2, {1}), {Create_Material("��쌋��", 2, {}), Create_Material("��", 2, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�m�[�u���T�t�@�C�A", 1, {1}), {Create_Material("������", 1, {}), Create_Material("�B���S�y", 1, {}), Create_Material("�z��", 2, {}), Create_Material("��", 1, {})}},
  {Create_Item("�[�ł̎�", 1, {1}), {Create_Material("�d�����t��", 1, {}), Create_Material("�d���̓ő�", 2, {}), Create_Material("��", 1, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�挩�̐�����", 1, {1}), {Create_Material("�y���f���[�N", 1, {}), Create_Material("�����̂�����", 5, {}), Create_Material("�z", 1, {}), Create_Material("�S�y", 1, {})}},
  {Create_Item("�H���̗��j��", 1, {1}), {Create_Material("�����̐j", 4, {}), Create_Material("�X�v���[�X", 2, {}), Create_Material("��", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�[�g�̐�", 1, {1}), {Create_Material("���̌���", 1, {}), Create_Material("���̕�", 2, {}), Create_Material("�Ζ�", 2, {}), Create_Material("�G���L�V��", 1, {})}},
  {Create_Item("���҂̐�", 1, {1}), {Create_Material("�[�g�̐�", 1, {}), Create_Material("���s��̊D", 5, {}), Create_Material("�G���L�V��", 2, {}), Create_Material("���", 1, {})}},
  {Create_Item("���ւ̎�", 1, {1}), {Create_Material("���z�̕�", 2, {}), Create_Material("�z��", 2, {}), Create_Material("����̗�", 1, {})}},
  {Create_Item("�~�l�����G�L�X", 2, {1}), {Create_Material("�A�v�R�[��", 1, {}), Create_Material("�z��", 2, {}), Create_Material("���a��", 1, {})}},
  {Create_Item("�΂���ފ����y", 1, {1}), {Create_Material("����̂���", 1, {}), Create_Material("�؍�", 2, {}), Create_Material("�z��", 2, {})}},
  {Create_Item("�����ȕ��i", 1, {1}), {Create_Material("�V���^�����^��", 1, {}), Create_Material("�z��", 2, {}), Create_Material("�R��", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("���΂������̘B����", 1, {1}), {Create_Material("���΂������̘B����", 1, {}), Create_Material("�z��", 2, {}), Create_Material("�S�y", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("���K�p�̘B����", 1, {1}), {Create_Material("���K�p�̘B����", 1, {}), Create_Material("�z��", 1, {}), Create_Material("�S�y", 2, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�����̘B����", 1, {1}), {Create_Material("�����̘B����", 1, {}), Create_Material("����", 1, {}), Create_Material("�A����", 2, {}), Create_Material("�S�y", 1, {})}},
  {Create_Item("�B�l�̘B����", 1, {1}), {Create_Material("�B�l�̘B����", 1, {}), Create_Material("����", 2, {}), Create_Material("�S�y", 1, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�d���̘B����", 1, {1}), {Create_Material("�d���̘B����", 1, {}), Create_Material("�B���S�y", 2, {}), Create_Material("����", 1, {}), Create_Material("���@�̓���", 1, {})}},
  {Create_Item("�Ñ�̘B����", 1, {1}), {Create_Material("�Ñ�̘B����", 1, {}), Create_Material("�B���S�y", 2, {}), Create_Material("����", 1, {}), Create_Material("���@�̓���", 1, {})}},
  {Create_Item("�����N���E�X�̓�", 1, {1}), {Create_Material("�����̂�����", 1, {}), Create_Material("�y���f���[�N", 1, {}), Create_Material("����", 1, {}), Create_Material("���f��", 1, {})}},
  {Create_Item("�����̐j", 1, {1}), {Create_Material("�������̐�", 1, {}), Create_Material("��", 2, {}), Create_Material("�S�y", 1, {})}},
  {Create_Item("�^���̌�", 1, {1}), {Create_Material("���ւ̎�", 1, {}), Create_Material("�O���̉ԕ�", 1, {}), Create_Material("�v���̗���", 1, {})}},
  {Create_Item("�w�N�Z�E�A�E���X", 1, {1}), {Create_Material("�V�����@���A", 2, {}), Create_Material("�\�E���X�g��", 2, {}), Create_Material("���", 2, {}), Create_Material("�_��̗�", 1, {})}},
  {Create_Item("�l�`�t�̎�", 1, {1}), {Create_Material("�S��̎�", 2, {}), Create_Material("���f��", 2, {}), Create_Material("�R��", 1, {})}},
  {Create_Item("����^�h�{��", 1, {1}), {Create_Material("���邨����", 1, {}), Create_Material("�G���L�V��", 1, {}), Create_Material("��̍ޗ�", 1, {}), Create_Material("��", 1, {})}}
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
void add_combination_Material(vector<vector<Material>> *combinations, vector<Material> combination, vector<Material> names, int counter){
  if(counter >= names.size()) combinations->push_back(combination);
  else{
    add_combination_Material(combinations, combination, names, counter + 1);
    combination.push_back(names[counter]);
    add_combination_Material(combinations, combination, names, counter + 1);
  }
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
bool isMix_ver2(Player player, Item_Recipe item_recipe){
  vector<vector<Material>> combinations;
  add_combination_Material(&combinations, {}, item_recipe.items_list, 0);
  for(auto itr = combinations.begin(); itr != combinations.end(); itr++){
    int required_amount = 0;
    for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
      required_amount += itr2->quantity;
    }
    int counter = 0;
    for(auto itr2 = player.items.begin(); itr2 != player.items.end(); itr2++){
      for(auto itr3 = itr->begin(); itr3 != itr->end(); itr3++){
        if(isString(encyclopedia[itr2->number].classes, itr3->name) || encyclopedia[itr2->number].name == itr3->name){
          counter += itr2->quantity;
          break;
        }
      }
    }
    if(counter < required_amount) return 0;
  }
  return 1;
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
void viewinItem_Recipe(Item_Recipe item_recipe){
  cout << "////////[" << encyclopedia[item_recipe.item.number].name << "'s Recipe]////////" << endl;
  cout << "//" << endl;
  for(auto itr = item_recipe.items_list.begin(); itr != item_recipe.items_list.end(); itr++){
    cout << "//  �E[" << itr->name << "] �~ " << itr->quantity << endl;
  }
  cout << "//" << endl;
  cout << "/////////////////////////////////" << endl;
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
    cout << "           -[DEF]-: " << player.status.def << endl;
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
vector<bool> Next_Corner_basic_prot(vector<vector<Mass>> v, Position position, int i/*���̕����ɓ������i�\�̈�j*/){
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
vector<bool> Next_Corner_basic(vector<vector<Mass>> v, Position position, int i/*���̕����ɓ������i�\�̈�j*/){
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
void Consume_Item_on_Mixing_ver2(Player *player, Item_Recipe item_recipe){
  cout << "Let's choose items to mix [" << encyclopedia[item_recipe.item.number].name << "]" << endl;
  vector<vector<Item>> candidates;
  candidates.resize(item_recipe.items_list.size());
  int i = 0;
  for(auto itr = item_recipe.items_list.begin(); itr != item_recipe.items_list.end(); itr++){
    for(auto itr2 = player->items.begin(); itr2 != player->items.end(); itr2++){
      if(isString(encyclopedia[itr2->number].classes, itr->name) || encyclopedia[itr2->number].name == itr->name) candidates[i].push_back(*itr2);
    }
    i++;
  }
  vector<int> require_material;
  for(auto itr = item_recipe.items_list.begin(); itr != item_recipe.items_list.end(); itr++){
    require_material.push_back(itr->quantity);
  }
  vector<vector<Item>> current_choices;
  vector<vector<Item>> current_candidates;
  vector<int> rest_material;
  while(1){
    bool isfull_choice = 0;
    current_choices = {};
    current_choices.resize(item_recipe.items_list.size());
    current_candidates = candidates;
    rest_material = require_material;
    while(!isfull_choice){
      viewinItem_Recipe(item_recipe);
      cout << "////////[Item]:[that you chosen]////////" << endl;
      cout << "//" << endl;
      i = 0;
      for(auto itr = current_choices.begin(); itr != current_choices.end(); itr++){
        cout << "//  [" << item_recipe.items_list[i].name << "]://" << endl;
        if(itr->size() == 0){
          cout << "//" << endl;
        }
        else{
          for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
            cout << "//    �E[" << encyclopedia[itr2->number].name << "]" << endl;
          }
        }
        i++;
      }
      cout << "//" << endl;
      cout << "////////////////////////////////" << endl;
      i = 0;
      int counter = 0;
      cout << "////////[Choose Item]://[Please item you use to mix]////////" << endl;
      cout << "[0]:Go Back One Step" << endl;
      for(auto itr = current_candidates.begin(); itr != current_candidates.end(); itr++){
        cout << "  ----[" << item_recipe.items_list[i].name << "]://" << endl;
        if(rest_material[i] == 0) cout << "        Completed!!" << endl;
        else if(itr->size() == 0) cout << endl;
        else{
          for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
            counter++;
            cout << "[" << counter << "]:" << encyclopedia[itr2->number].name << " �~ " << itr2->quantity << endl;
          }
        }
        i++;
      }
      int choice_number = input_int_zero(counter);
      int choice_category_number;
      int choice_item_number;
      if(choice_number == 0) break;
      else {
        i = 0;
        int counter2 = 0;
        for(auto itr = current_candidates.begin(); itr != current_candidates.end(); itr++){
          if(rest_material[i] != 0){
            for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
              counter2++;
              if(counter2 == choice_number){
                current_choices[i].push_back(*itr2);
                choice_item_number = itr2->number;
                rest_material[i]--;
              }
            }
          }
          i++;
        }
        i = 0;
        for(auto itr = current_candidates.begin(); itr != current_candidates.end(); itr++){
          for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
            if(itr2->number == choice_item_number){
              if(itr2->quantity > 1) itr2->quantity--;
              else{
                current_candidates[i].erase(itr2);
              }
              break;
            }
          }
          i++;
        }
      }
      isfull_choice = 1;
      for(auto itr = rest_material.begin(); itr != rest_material.end(); itr++){
        isfull_choice = (*itr == 0) && isfull_choice;
      }
    }
    int choice_number;
    if(!isfull_choice){
      cout << "Do you continue to mix?" << endl;
      cout << "[0]:No" << endl;
      cout << "[1]:Yes" << endl;
      choice_number = input_int_zero(1);
      if(choice_number == 0) break;
    }
    else{
      cout << "////////[Item]:[that you chosen]////////" << endl;
      cout << "//" << endl;
      i = 0;
      for(auto itr = current_choices.begin(); itr != current_choices.end(); itr++){
        cout << "//  [" << item_recipe.items_list[i].name << "]://" << endl;
        if(itr->size() == 0){
          cout << "//" << endl;
        }
        else{
          for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
            cout << "//    �E[" << encyclopedia[itr2->number].name << "]" << endl;
          }
        }
        i++;
      }
      cout << "//" << endl;
      cout << "////////////////////////////////" << endl;
      cout << "There are materials you consume to mix. Are you OK?" << endl;
      cout << "[0]:No" << endl;
      cout << "[1]:Yes" << endl;
      choice_number = input_int_zero(1);
      if(choice_number == 1){
        for(auto itr = current_choices.begin(); itr != current_choices.end(); itr++){
          for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
            itr2->quantity = 1;
            Consume_Item(player, *itr2);
          }
        }
        break;
      }
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
  item.number = i;//Random(encyclopedia.size() - 1);
  item.quantity = 1;
  item.option_int = {1};
  cout << "you got ..." < endl;
  viewinItem(item);
  return item;
}
void Item_Mix(Player *player){
  int i = 0;
  int recipe_number = 0;
  vector<int> candidates;
  for(auto itr = item_recipe.begin(); itr != item_recipe.end(); itr++){
    if(isMix_ver2(*player, *itr)){
      i++;
      cout << "[" << i << "]://" << encyclopedia[itr->item.number].name << endl;
      viewinItem_Recipe(*itr);
      candidates.push_back(recipe_number);
    }
    recipe_number++;
  }
  if(i == 0){
    cout << "You can't mix items" << endl;
  }
  else{
    Item_Recipe choice_recipe = item_recipe[candidates[input_int(i) - 1]];
    Consume_Item_on_Mixing_ver2(player, choice_recipe);
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
      player->status.def = encyclopedia_phy_lv[post_level].def;
      cout << "--------[" << player->name << "] PHYSICAL LEVEL UP to [" << post_level << "] !!--------" << endl;
      cout << "-[HP]-: " << pre_hp << "/" << encyclopedia_phy_lv[pre_level].hp << " -> " << player->status.hp << "/" << encyclopedia_phy_lv[post_level].hp << " (+" << increase << ")!" << endl;
      cout << "-[STR]- " << encyclopedia_phy_lv[pre_level].str << " -> " << encyclopedia_phy_lv[post_level].str << " (+" << encyclopedia_phy_lv[post_level].str - encyclopedia_phy_lv[pre_level].str << ")!" << endl;
      cout << "-[DEF]- " << encyclopedia_phy_lv[pre_level].def << " -> " << encyclopedia_phy_lv[post_level].def << " (+" << encyclopedia_phy_lv[post_level].def - encyclopedia_phy_lv[pre_level].def << ")!" << endl;
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

    �@�@--�^��--
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
    player_i.status = {encyclopedia_phy_lv[1].hp, encyclopedia_phy_lv[1].str, encyclopedia_phy_lv[1].def, 1, 0, 1, 0};
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
