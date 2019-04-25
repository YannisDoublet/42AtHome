import React, {Component} from 'react';
import {connect} from 'react-redux';
import Card from '../../components/Widgets/Card'
import './home.css'

class HomeContainer extends Component {
    render() {
        console.log(this.props);
        return (
            <div>
                <div className="home_image">
                </div>
             <Card />
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {
        user: state.user
    };
}

export default connect(mapStateToProps)(HomeContainer);
