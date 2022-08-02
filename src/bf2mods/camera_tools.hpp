//
// Created by block on 6/21/2022.
//

#pragma once

#include <bf2mods/engine/mm/math_types.hpp>

#include "bf2mods/UpdatableModule.hpp"

namespace bf2mods {

	struct CameraTools : public bf2mods::UpdatableModule {

		struct FreecamState {
			bool isOn;
			mm::Mat44 matrix;
			float fov;
			float camSpeed;
		};
		static FreecamState Freecam;

		static void DoFreeCameraMovement();

		void Initialize() override;
		bool NeedsUpdate() const override { return true; }
		void Update() override;
	};

} // namespace bf2mods
