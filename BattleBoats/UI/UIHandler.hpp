#ifndef UI_UIHandler_hpp
#define UI_UIHandler_hpp

namespace UI
{
	struct UIHandler
	{
		UIHandler() = default;

		virtual void launch() = 0;

		virtual ~UIHandler() = 0;
	};



	inline UIHandler::~UIHandler() {}

}




#endif // UI_UIHandler_hpp

