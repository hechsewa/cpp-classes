//
// Created by Student on 04/05/17.
//

#include <iostream>
#include <vector>
#include <string>
#include <Student.h>
#include "Serialization.h"

using namespace std;

namespace academia {

    std::string TypeToString(Room::Type type) {
        switch(type) {
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }
    }


    void Room::Serialize(Serializer *ser) {
        ser->Header("Room");
        ser->IntegerField("id", id_);
        ser->StringField("name", name_);
        ser->StringField("type", type_);
        ser->Footer("Room");

    }

    Room::Room(int id_, const string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    XmlSerializer::XmlSerializer(ostream *out_) : Serializer(out_) {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {

    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {

    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const vector<reference_wrapper<const academia::Serializable>> &value) {

    }

    void XmlSerializer::Header(const std::string &object_name) {

    }

    void XmlSerializer::Footer(const std::string &object_name) {

    }

}

