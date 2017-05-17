#pragma once

#include "defs.h"
#include "criteria.h"
#include <vector>
#include <algorithm>

class Path {
public:
    Path() : from(0), to(0) {}
    Path(Element * begin, Element * end) {
        if ( !Criteria::isPhysical(begin) ) throw;
        if ( !Criteria::isNode(begin) ) throw;
        if ( !Criteria::isPhysical(end) ) throw;
        if ( !Criteria::isNode(end) ) throw;

        from = begin;
        to = end;
        path = std::vector<Element *>();
    }

    inline bool isZeroPath() const {
        return from == to;
    }

    inline int length() const {
        path.size() + 2; 
    }

    inline bool isValid() const {
        return from != 0 && to != 0;
    }

    inline bool addElement(Element * element) {
        if ( !Criteria::isPhysical(element) ) return false;
        path.push_back(element);
        return true;
    }

    inline void revert() {
        if ( !isValid() )
            return;

        Element * tmp = from;
        from = to;
        to = tmp;
        std::reverse(path.begin(), path.end()); 
    }

    std::vector<Element *> getPath() const { 
        return path;
    }

    Element * getFirstNode() const {
        return from;
    }

    Element * getLastNode() const {
        return to;
    }

    Element * setFirstNode(Element * f) {
        from = f;
    }

    Element * setLastNode(Element * t) {
        to = t;
    }


private:
    std::vector<Element *> path;
    Element * from;
    Element * to;
};