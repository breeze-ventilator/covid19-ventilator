
export default class Messager {
	constructor(updateData) {
		this.updateData = updateData;
		this.listenForData();
	}

	listenForData() {
		setInterval( () => {
			let val = Math.random()*20.0 - 10.0;
			this.updateData({
				type: 'tidal volume',
				value: val
			})
		}, 1000/60)
	}
}

/* App
	updateData(dataType) {
		update the react children components
	}
	App.messager = Messager(updateData)
	when messager gets new data, it would process the data a

*/