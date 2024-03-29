//
//  glProgramWithMyUnifos.cpp
//  HelloCpp
//
//  Created by wantnon(yang chao) on 14-2-18.
//
//

#include "glProgramWithMyUnifos.h"

void CGLProgramWithMyUnifos::passUnifoValue1f(string unifoName,GLfloat v){
    glUniform1f(m_unifoMap[unifoName],v);
}
void CGLProgramWithMyUnifos::passUnifoValue1i(string unifoName,GLint v){
    glUniform1i(m_unifoMap[unifoName],v);
}
void CGLProgramWithMyUnifos::passUnifoValueMatrixNfv(string unifoName,const GLfloat *array,int arrayLen){
    assert(arrayLen==4||arrayLen==9||arrayLen==16);
    switch (arrayLen) {
        case 4:
        glUniformMatrix2fv(m_unifoMap[unifoName],1,GL_FALSE,array);
        break;
        case 9:
        glUniformMatrix3fv(m_unifoMap[unifoName],1,GL_FALSE,array);
        break;
        case 16:
        glUniformMatrix4fv(m_unifoMap[unifoName],1,GL_FALSE,array);
        break;
        default:
        assert(false);
        break;
    }
    
}
void CGLProgramWithMyUnifos::passUnifoValueNfv(string unifoName,const GLfloat*array,int arrayLen){
    assert(arrayLen>=1&&arrayLen<=4);
    switch (arrayLen) {
        case 1:
        glUniform1fv(m_unifoMap[unifoName],1,array);
        break;
        case 2:
        glUniform2fv(m_unifoMap[unifoName],1,array);
        break;
        case 3:
        glUniform3fv(m_unifoMap[unifoName],1,array);
        break;
        case 4:
        glUniform4fv(m_unifoMap[unifoName],1,array);
        break;
        default:
        assert(false);
        break;
    }
    
}
void CGLProgramWithMyUnifos::passUnifoValueNiv(string unifoName,const GLint*array,int arrayLen){
    assert(arrayLen>=1&&arrayLen<=4);
    switch (arrayLen) {
        case 1:
        glUniform1iv(m_unifoMap[unifoName],1,array);
        break;
        case 2:
        glUniform2iv(m_unifoMap[unifoName],1,array);
        break;
        case 3:
        glUniform3iv(m_unifoMap[unifoName],1,array);
        break;
        case 4:
        glUniform4iv(m_unifoMap[unifoName],1,array);
        break;
        default:
        assert(false);
        break;
    }
    
}
void CGLProgramWithMyUnifos::passUnifoValueMatrixNfv(string unifoName,const vector<GLfloat>&valueList){
    passUnifoValueMatrixNfv(unifoName, &valueList.front(), (int)valueList.size());
}
void CGLProgramWithMyUnifos::passUnifoValueNfv(string unifoName,const vector<GLfloat>&valueList){
    passUnifoValueNfv(unifoName, &valueList.front(), (int)valueList.size());
}
void CGLProgramWithMyUnifos::passUnifoValueNiv(string unifoName,const vector<GLint>&valueList){
    passUnifoValueNiv(unifoName, &valueList.front(), (int)valueList.size());
}

