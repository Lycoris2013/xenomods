#pragma once

#include <bf2mods/engine/mm/math_types.hpp>
#include <fmt/format.h>

#include "bf2mods/utils.hpp"

namespace bf2mods {

	struct Options {
		enum class BdatScrambleType : std::uint8_t {
			Off,
			ScrambleIndex,
			ShowSheetName,
			Count
		};

		/**
		 * Reset to default options.
		 */
		constexpr void Reset() {
			bdatScrambleType = Options::BdatScrambleType::Off;

			disableFallDamage = true;
			movementSpeedMult = 1.f;
			enableUIRendering = true;
			enableDebugRendering = true;
		}

		BdatScrambleType bdatScrambleType;

		bool disableFallDamage;
		float movementSpeedMult;
		bool enableUIRendering;
		bool enableDebugRendering;
	};

	struct Bf2ModsState {
		constexpr explicit Bf2ModsState() {
			Reset();
		}

		/**
		 * Reset to clean state.
		 */
		constexpr void Reset() {
			// Reset options
			options.Reset();

			tempInt = 1;

			moonJump = false;
		}

		/**
		 * Current options.
		 */
		Options options {};

		int tempInt {};

		bool moonJump {};
	};

	/**
	 * Get singleton state.
	 */
	Bf2ModsState& GetState();

} // namespace bf2mods

template<>
struct fmt::formatter<bf2mods::Options::BdatScrambleType> : fmt::formatter<std::string_view> {
	template<typename FormatContext>
	inline auto format(bf2mods::Options::BdatScrambleType type, FormatContext& ctx) {
		using enum bf2mods::Options::BdatScrambleType;
		std::string_view name = "unknown";

		switch(type) {
			case ScrambleIndex: name = "Scramble Index"; break;
			case ShowSheetName: name = "Show Bdat Sheet Name"; break;
			case Off: name = "Disabled"; break;
		};

		return formatter<std::string_view>::format(name, ctx);
	}
};