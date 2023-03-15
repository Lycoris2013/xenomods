//
// Created by block on 1/18/2023.
//

#pragma once

#include "UpdatableModule.hpp"
#include <string>
#include <vector>

namespace xenomods {

	struct EventDebugUtils : public xenomods::UpdatableModule {

		static int RegistrationIndex;
		static int CurrentIndex;
		static unsigned long ActiveBits;
		static std::vector<std::string> FuncNames;

		static bool ShouldUpdate;

		void Initialize() override;
		bool NeedsUpdate() const override {
			return ShouldUpdate;
		}
		void Update() override;
	};

} // namespace xenomods