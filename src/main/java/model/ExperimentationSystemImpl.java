package model;

public class ExperimentationSystemImpl implements ExperimentationSystem {

	private SystemStatus status;

	public ExperimentationSystemImpl() {
		status = SystemStatus.Running;
	}

	@Override
	public SystemStatus getStatus() {
		return status;
	}

	@Override
	public void setStatus(SystemStatus status) {
		this.status = status;
	}
}
