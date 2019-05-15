#ifndef __ARRAY_H_
#define __ARRAY_H_

#include "default.h"

class PresentInfo
{
public:
    PresentInfo(int strike, int ball);
    PresentInfo(PresentInfo& cpy);
    bool isOut() const;
    int Strike() const;
    int Ball() const;
private:
    int Number[3];
    /*
     idx 0 <- elem : 0 = not ball / 1 = ball
     idx 1 <- elem : number of strike
     idx 2 <- elem : number of ball
    */
};

class Array
{
public:
    Array(int Difficulty);
    ~Array();
    int& operator[](int idx);
    PresentInfo* Check(Array& Present) const;
    bool SetArray(string& Numbers);
    void clear();

protected:
    virtual bool push_back(int elem);

protected:
    vector<int> arr;
    int ElemNum;
    /*
     3 <- EASY
     4 <- NORMAL
     5 <- HARD
    */
};

class Answer : public Array
{
public:
    Answer(int Difficulty);
protected:
    void SetRandomNumber();
    virtual bool push_back(int randomNum); // 랜덤넘버 중복삽입을 막기 위한 유틸리티함수
};

#endif