#include "turing-pulse-module-widget.hh"
#include "turing-pulse-module.hh"

turing_pulse_module_widget::turing_pulse_module_widget(Module* module) : ModuleWidget(module) {
   setPanel(SVG::load(assetPlugin(pluginInstance, "res/AlanPulses.svg")));

   addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
   addChild(Widget::create<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
   addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
   addChild(Widget::create<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
  
   addInput(Port::create<DavidLTPort>
	    (Vec(25, 45),
	     Port::INPUT,
	    module,
	    turing_pulse_module::I_EXPANDER));

  addInput(Port::create<DavidLTPort>
	   (Vec(65, 45),
	    Port::INPUT,
	    module,
	    turing_pulse_module::I_PULSE));
  
  for (size_t i = 0;
       i < 7;
       i++)
  {
     addOutput(Port::create<DavidLTPort>
	       (Vec(15, 80 + (30 * i)),
		Port::OUTPUT,
		module,
		turing_pulse_module::O_GATE1 + i));

     addChild(createLight<MediumLight<BlueLight>>
	      (Vec(43, 88 + (30 * i)),
	       module,
	       turing_pulse_module::L_GATE1 + i));
  }

  for (size_t i = 0;
       i < 4;
       i++)
  {
     addOutput(Port::create<DavidLTPort>
	       (Vec(95, 80 + (60 * i)),
		Port::OUTPUT,
		module,
		turing_pulse_module::O_GATE1P2 + i));

     addChild(createLight<MediumLight<BlueLight>>
	      (Vec(123, 88 + (60 * i)),
	       module,
	       turing_pulse_module::L_GATE1P2 + i));
  }
}


