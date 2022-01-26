//
// Created by CQ07 on 2021-12-10.
//

#include "Stop.h"

Stop::Stop(long id, const string &name, double latitude, double longitude) : id(id), name(name), latitude(latitude),
                                                                             longitude(longitude) {}

void Stop::print() {
    cout<< id << endl << name << endl << latitude << " " << longitude << endl;

}