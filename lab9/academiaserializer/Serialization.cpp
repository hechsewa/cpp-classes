//
// Created by Student on 04/05/17.
//

#include <iostream>
#include <vector>
#include <string>
#include "Serialization.h"

using namespace std;

namespace academia {

    std::string Room::TypeToString(Room::Type type) const {
        switch(type){
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    void Room::Serialize(Serializer *item) const {

        item->Header("room");
        item->IntegerField("id", id_);
        item->StringField("name", name_);
        item->StringField("type", TypeToString(room_));
        item->Footer("room");

    }



    /*****XmlSerializer ***********************/

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        Header(field_name);
        (*out_)<<value;
        Footer(field_name);
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        (*out_)<<"<"<<field_name<<">";
        for(const Serializable &i: value){
            i.Serialize(this);
        }
        (*out_)<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        (*out_) << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        (*out_) << "<\\" << object_name << ">";
    }

   /*****************Json Serializer *****************************/


    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        comma_thrower();
        (*out_)<<"\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        comma_thrower();
        (*out_)<<"\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        comma_thrower();
        (*out_)<<"\"" << field_name << "\": " << value;
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        comma_thrower();
        (*out_)<<"\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        comma_thrower();
        (*out_)<<field_name;
        value.Serialize(this);
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        comma_thrower();
        (*out_)<<"\""<<field_name<<"\": [";
        if (value.size()!=0){
            is_first=true;
        }
        for(const Serializable &i: value){
            SerializableField(" ", i);
        }
        (*out_)<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        is_first=true;
        (*out_)<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        (*out_)<< "}";
    };

    void JsonSerializer::comma_thrower(){
        if(!is_first){
            (*out_)<<", "; }
        else is_first=false;
    }

    /********************BUILDING ***************************/

    Building::Building(int id_, const std::string &name_, std::vector<std::reference_wrapper<const Serializable>> rooms): id_(id_), name_(name_), rooms_(rooms){
    }

    void Building::Serialize(Serializer *item) const {
        item->Header("building");
        item->IntegerField("id", id_);
        item->StringField("name", name_);
        item->ArrayField("rooms", rooms_);
        item->Footer("building");
    }
}

