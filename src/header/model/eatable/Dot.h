//
// Created by iman on 08/03/23.
//

#ifndef PAS_CMAN_DOT_H
#define PAS_CMAN_DOT_H

#include "header/model/StaticGameObject.h"
#include "header/model/component/EatableComponent.h"

class Dot : public StaticGameObject, public EatableComponent {
public:
    Dot();
};


#endif //PAS_CMAN_DOT_H
