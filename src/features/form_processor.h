// This file is part of NameTag.
//
// Copyright 2013 by Institute of Formal and Applied Linguistics, Faculty of
// Mathematics and Physics, Charles University in Prague, Czech Republic.
//
// NameTag is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.
//
// NameTag is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with NameTag.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "common.h"
#include "ner_sentence.h"
#include "ner/entity_map.h"
#include "utils/binary_decoder.h"
#include "utils/binary_encoder.h"

namespace ufal {
namespace nametag {

class form_processor {
 public:
  virtual ~form_processor();

  virtual bool init(int window, const vector<string>& args);
  virtual void load(binary_decoder& data);
  virtual void save(binary_encoder& enc);
  virtual ner_feature freeze(entity_map& entities);

  virtual void process_form(int form, ner_sentence& sentence, ner_feature offset, string& buffer) const = 0;

 protected:
  int window;

  inline ner_feature lookup(const string& key) const {
    if (adding_features) {
      return map.emplace(key, window * map.size()).first->second;
    } else {
      auto it = map.find(key);
      return it != map.end() ? it->second : ner_feature_unknown;
    }
  }

  mutable unordered_map<string, ner_feature> map;

 private:
  bool adding_features = false;

  // Factory method
 public:
  static form_processor* create(const string& name);
};

} // namespace nametag
} // namespace ufal
