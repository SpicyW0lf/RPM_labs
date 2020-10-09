#pragma once
#include <string>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
struct Square
{
    int square_;
    explicit Square(const int& square) : square_(square) {};
};
struct Size
{
    int size_;
    explicit Size(const int& size) : size_(size) {};
};
struct Floor
{
    int floor_;
    explicit Floor(const int& floor) : floor_(floor) {};
};
struct Area
{
    string area_;
    explicit Area(const string& area) : area_(area) {};
};
struct Apart {
    Square square_;
    Size size_;
    Floor floor_;
    Area area_;
    Apart(const Area& area, const Floor& floor, const Size& size, const Square& square) : square_(square), size_(size), floor_(floor), area_(area) {};
};
ostream& operator <<(ostream& stream, const Apart& apart) {
    stream << "Apart in area: " << apart.area_.area_ << " on " << apart.floor_.floor_ << " floor" << " with size: " << apart.size_.size_ << " and square: " << apart.square_.square_ << endl;
    return stream;
}
class File {
public:

    void AddApart(const Apart& apart) {
        aparts.emplace_back(apart);
    }
    void FindApart(const Apart& apart) {
        auto itter = find_if(aparts.begin(), aparts.end(), [apart](const Apart& apart_) {
            auto x = apart_.size_.size_ / 10;
            if ((apart.size_.size_ >= (apart_.size_.size_ - x)) && (apart.size_.size_ <= (apart_.size_.size_ + x)) &&
                (apart.floor_.floor_ >= (apart_.floor_.floor_ - x)) && (apart.floor_.floor_ <= (apart_.floor_.floor_ + x)) &&
                (apart.square_.square_ >= (apart_.square_.square_ - x)) && (apart.square_.square_ <= (apart_.square_.square_ + x))) {
                return true;
            }
            else return false;
        });
        if (itter == aparts.end()) {
            aparts.emplace_back(apart);
            cout << "Nothing found" << endl;
        }
        else {
            cout << *itter << endl;
            aparts.erase(itter);
        }
    }
    void ShowAparts() const {

        for (auto begin = aparts.begin();
             begin != aparts.end();
             ++begin) {
            cout << *begin;
        }
    }
private:
    list<Apart> aparts;
};
