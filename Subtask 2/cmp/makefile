make:
	@ echo "Running Continuous Comparison.."
	@ ./continuous_core
	@ ./continuous_oblas
	@ ./continuous_mkl

	@ echo "Running Step Comparison.."
	@ ./continuous_core core
	@ ./continuous_oblas oblas
	@ ./continuous_mkl mkl
    
	@ echo "Plotting.."
	@ ./plot.sh
	
