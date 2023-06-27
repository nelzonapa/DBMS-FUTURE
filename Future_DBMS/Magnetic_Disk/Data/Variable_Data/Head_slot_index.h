#ifndef HEAD_SLOT_INDEX_H
#define HEAD_SLOT_INDEX_H

class Head_slot_index
{
private:
    int num_slots_index;
    int direc_final_index;
    int direc_vacio_delete;
public:
    Head_slot_index();
    Head_slot_index(int _num_slots_index, int _direc_final_index, int _direc_vacio_delete);
    ~Head_slot_index();

    //SET
    void set_num_slots_index(int _num_slots_index);
    void set_direc_final_index(int _direc_final_index);
    void set_direc_vacio_delete(int _direc_vacio_delete);

    //GET
    int get_num_slots_index();
    int get_direc_final_index();
    int get_direc_vacio_delete();

    void print_info_Head_slots_index();
};

#endif