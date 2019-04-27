import React, {Component} from 'react';
import {connect} from 'react-redux';
import '../login.css'

class SignUpForm extends Component {
    render() {
        return (
            <div>
                Hola
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {};
}

export default connect(mapStateToProps)(SignUpForm);
