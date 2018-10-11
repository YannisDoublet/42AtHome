<?php
class NightsWatch
{
	public $tab = array();
	public function recruit($inst)
	{
		if ($inst instanceof IFighter)
			$this->tab[] = $inst;
	}
	public function fight()
	{
		foreach($this->tab as $inst)
		{
			$inst->fight();
		}
	}
}
?>