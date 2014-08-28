// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ALBERTENGINE_H
#define ALBERTENGINE_H

#include <vector>
#include <map>
#include "item.h"

using std::vector;
using std::map;

class AlbertEngine
{
public:
	explicit AlbertEngine();
	~AlbertEngine();
	static AlbertEngine* instance(){
		if (_instance == nullptr)
			_instance = new AlbertEngine;
		return _instance;
	}
	void buildIndex();
//	void loadIndex();
//	void saveIndex();
	void request(const QString &req, std::vector<const Items::AbstractItem *> &result);

private:
	static AlbertEngine *_instance;
	vector<Items::AbstractItem*> _index;
	vector<const Items::AbstractItem * > _result;
};

#endif // ALBERTENGINE_H
