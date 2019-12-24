{Modifiers
	{modifier
		{name long_range_flares}
		{filter
			{include
				{tag
					{tag longshot}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 10}
			}
		}
	}
	{modifier
		{name mgun_trench}
		{filter
			{include
				{tag
					{tag mgun_fire}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 2}
			}
		}
	}
	{modifier
		{name mow_range}
		{filter
			{include
				{tag
					{tag mow}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 0.7}
			}
		}
	}
	{modifier
		{name mow_range2}
		{filter
			{include
				{tag
					{tag mow2}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 0.4}
			}
		}
	}
}