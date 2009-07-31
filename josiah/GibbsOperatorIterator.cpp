/*
 *  GibbsOperatorIterator.cpp
 *  josiah
 *
 *  Created by Abhishek Arun on 30/07/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "GibbsOperatorIterator.h"
#include "GibbsOperator.h"
namespace Josiah {
  void FlipIterator::next() {
    if (m_thisPos == NOT_FOUND) {
      m_thisPos++;
      m_thatPos = m_thisPos + 1; //This is a precondition   
      return;
    }  
    
    size_t new_thatPos = m_thatPos + m_direction;
    if (new_thatPos != NOT_FOUND && new_thatPos >= 0 && new_thatPos < m_operator->GetSplitPoints().size()) {
      m_thatPos = new_thatPos;
      return;
    }
    
    if (new_thatPos == NOT_FOUND){
      m_direction = 1;
      m_thisPos++;
      m_thatPos = m_thisPos;
      next();
    }  
    else {
      m_direction = -1;
      m_thatPos = m_thisPos;
      next();
    }  
  }
  
  bool FlipIterator::keepGoing() {
    if (m_thisPos == NOT_FOUND && m_thatPos == NOT_FOUND && m_size == NOT_FOUND)
      return true;
    if (m_thisPos == m_operator->GetSplitPoints().size() -1 && m_direction == -1 && m_thatPos == 0)
      return false;
    if (m_operator->GetSplitPoints().size() < 2)
      return false;
    return true;
  }
  
}
