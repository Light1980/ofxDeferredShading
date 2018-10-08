#pragma once
#include "ofMain.h"
#include "Processor.hpp"
#include "Blur.h"

namespace ofxDeferred {
	class BloomPass : public RenderPass {
	private:
		ofFbo blurred;
		Blur blur;
		
		ofShader lumaShader;
		ofFbo lumaFbo;

		float lumaThres;

	public:
		using Ptr = shared_ptr<BloomPass>;
		
		BloomPass(const glm::vec2& size);
		void update(const ofCamera& cam) {}
		void render(ofFbo& readFbo, ofFbo& writeFbo, GBuffer& gbuffer);

		void setThreshold(float thres) { lumaThres = thres; }
	};
}
