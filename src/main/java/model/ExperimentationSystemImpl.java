package model;

public class ExperimentationSystemImpl implements ExperimentationSystem {

	private SystemStatus status;

	public ExperimentationSystemImpl() {
		status = SystemStatus.Ready;
	}

	public SystemStatus getStatus() {
		return status;
	}

	public void setStatus(SystemStatus status) {
		this.status = status;
	}
}
