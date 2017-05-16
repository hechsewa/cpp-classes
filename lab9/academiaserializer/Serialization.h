//
// Created by Student on 04/05/17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <initializer_list>
#include <experimental/optional>
#include <sstream>

using namespace std;

namespace academia {

    class Serializer;

    /********SERIALIZABLE ******************************/
    class Serializable{
    public:
        virtual void Serialize(Serializer *ser) const =0;
        std::vector<std::reference_wrapper<Serializable>> ref;
    };

    /******************* SERIALIZER ****************************/
    class Serializer {
    public:
        Serializer(){};
        Serializer(std::ostream *out) : out_(out) {};
        virtual ~Serializer(){};

        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    protected:
        std::ostream *out_;
    };


    /***************** XML SERIALIZER **************************/
    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(){};
        XmlSerializer(std::ostream *out_):Serializer(out_){};
        virtual ~XmlSerializer(){};

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    };
    /********************* JSON SERIALIZER ****************************/

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(){};
        JsonSerializer(std::ostream *out):Serializer(out){
            is_first=true;
        };
        virtual ~JsonSerializer(){};

        void comma_thrower();

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    private:
        bool is_first;

    };

    /******************* ROOM ******************************/
    class Room : public Serializable {
    public:

        enum class Type{
            LECTURE_HALL,
            COMPUTER_LAB,
            CLASSROOM,
        };

        Room(int id_, const string &name_, Room::Type type): id_(id_), name_(name_), room_(type) {}
        void Serialize(Serializer *item) const override;
        std::string TypeToString(Type type) const;

    private:
        int id_;
        std::string name_;
        Type room_;
    };


    /************************ BUILDING **************************/
    class Building : public Serializable {
    public:
        Building(){};
        Building(int id_, const std::string &name_, std::vector<std::reference_wrapper<const Serializable>> rooms);
        void Serialize(Serializer *item) const override;
        virtual ~Building(){};
        int Id(){return id_;}
    private:
        int id_;
        std::string name_;
        std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };

};

#endif //JIMP_EXERCISES_SERIALIZATION_H
