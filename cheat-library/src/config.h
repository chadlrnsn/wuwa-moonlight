#pragma once

namespace config {
	namespace multihit {
		inline bool enabled = true;
		inline int max_hits = 100;
		inline int min_hits = 2;
		inline int hits = 10;
	}

	namespace godmode {
		inline bool enabled = false;
	}
}