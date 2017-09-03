#ifndef XANADU_SINGLE_INCLUDE_XMEMORY_H
#define XANADU_SINGLE_INCLUDE_XMEMORY_H

/***************************************************************************************
Xanadu Open GL Windows Game Engine
Copyright (C) 2017  William W. Westlake Jr.
wwestlake@lagdaemon.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************************/

#include "defines.h"
#include <vector>
#include <stdlib.h>
#include <boost/shared_ptr.hpp>
#include <boost/intrusive/avltree.hpp>
#include <map>

namespace Xanadu {
	namespace Engine {

		using namespace std;
		using namespace boost::intrusive;

		class XMemory {
		public:
			XMemory(size_t size);
			~XMemory();

			char* operator[](size_t index)
			{
				return &(_memory[index]);
			}

			char* GetFreePtr() {
				return _free;
			}

			void SetFreePtr(char* free) {
				_free = free;
			}

			size_t GetSize() {
				return _size;
			}

			bool IsAvailable(size_t size) {
				return ((size_t)_free + size) < ((size_t)_memory + _size);
			}

		private:
			char* _memory;
			char* _free;
			size_t _size;
		};


	}
}

#endif



