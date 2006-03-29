#ifndef FLOATING_TEXTBOX_H_INCLUDED
#define FLOATING_TEXTBOX_H_INCLUDED

#include "global.hpp"

#include "display.hpp"
#include "scoped_resource.hpp"
#include "team.hpp"
#include "unit.hpp"
#include "widgets/textbox.hpp"

namespace gui{
	enum TEXTBOX_MODE { TEXTBOX_NONE, TEXTBOX_SEARCH, TEXTBOX_MESSAGE,
		        TEXTBOX_COMMAND };

	class floating_textbox{
	public:
		floating_textbox();

		void close(display& gui);
		void update_location(display& gui);
		void show(gui::TEXTBOX_MODE mode, const std::string& label, 
			const std::string& check_label, bool checked, display& gui);
		void tab(std::vector<team>& teams, const unit_map& units, display& gui);
		bool active() const { return box.get() != NULL; }

		util::scoped_ptr<gui::textbox> box;
		util::scoped_ptr<gui::button> check;

		TEXTBOX_MODE mode;

		std::string label_string;
		int label;
	private:
	};
}

#endif
